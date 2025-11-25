#include <bits/stdc++.h>
using namespace std;

class Dayso {
private:
    int n;
    int *a;

public:
    Dayso() {
        n = 0;
        a = nullptr;
    }

    // Toán tử nhập >>
    friend istream& operator >> (istream &is, Dayso &d) {
        cout << "Nhap so phan tu n: ";
        is >> d.n;

        d.a = new int[d.n];
        cout << "Nhap " << d.n << " so nguyen:\n";
        for (int i = 0; i < d.n; i++) {
            is >> d.a[i];
        }
        return is;
    }

    // Toán tử xuất <<
    friend ostream& operator << (ostream &os, const Dayso &d) {
        os << "Day so: ";
        for (int i = 0; i < d.n; i++) {
            os << d.a[i] << " ";
        }
        return os;
    }

    // Hàm tính tổng
    int tong() const {
        int s = 0;
        for (int i = 0; i < n; i++) s += a[i];
        return s;
    }

    // Hàm tính trung bình cộng
    double tbc() const {
        if (n == 0) return 0;
        return (double)tong() / n;
    }

    ~Dayso() {
        delete[] a;
    }
};

int main() {
    Dayso d;

    cin >> d;       // dùng toán tử >>
    cout << d << endl;  // dùng toán tử <<

    cout << "Tong day = " << d.tong() << endl;
    cout << "Trung binh cong = " << d.tbc() << endl;

    return 0;
}
