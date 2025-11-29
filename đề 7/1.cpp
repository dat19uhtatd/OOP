#include <bits/stdc++.h>
using namespace std;

class Ds_nguyen {
private:
    int n;
    int *a;

public:
    Ds_nguyen() {
        n = 0;
        a = nullptr;
    }

    // Hàm nhập bằng toán tử >>
    friend istream& operator>>(istream &in, Ds_nguyen &ds) {
        cout << "Nhap so phan tu: ";
        in >> ds.n;

        ds.a = new int[ds.n];
        cout << "Nhap day so nguyen:\n";
        for (int i = 0; i < ds.n; i++) {
            in >> ds.a[i];
        }
        return in;
    }

    // Tính trung bình cộng các số dương
    double tbcDuong() {
        int sum = 0, dem = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                sum += a[i];
                dem++;
            }
        }
        if (dem == 0) return 0;
        return (double)sum / dem;
    }

    // Kiểm tra số chính phương
    bool chinhPhuong(int x) {
        if (x < 0) return false;
        int k = sqrt(x);
        return k * k == x;
    }

    // Đếm số phần tử chính phương
    int demChinhPhuong() {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (chinhPhuong(a[i])) cnt++;
        }
        return cnt;
    }

    // In dãy
    void in() {
        cout << "Day so: ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }

    ~Ds_nguyen() {
        delete[] a;
    }
};

int main() {
    Ds_nguyen ds;

    cin >> ds;

    cout << "\n=== Ket qua ===\n";
    ds.in();

    cout << "Trung binh cong cac so duong = " << ds.tbcDuong() << endl;
    cout << "So phan tu la so chinh phuong = " << ds.demChinhPhuong() << endl;

    return 0;
}
