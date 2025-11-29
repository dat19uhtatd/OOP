#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tu, mau;
    void rutgon() {
        int g = __gcd(tu, mau);
        tu /= g;
        mau /= g;
        if (mau < 0) { tu = -tu; mau = -mau; }
    }

public:
    PhanSo() : tu(0), mau(1) {}
    PhanSo(int tu, int mau) : tu(tu), mau(mau) {
        if (mau == 0) mau = 1;
        rutgon();
    }
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
        if (mau == 0) mau = 1;
        rutgon();
    }
    PhanSo operator * (const PhanSo &p) const {
        PhanSo kq(tu * p.tu, mau * p.mau);
        return kq;
    }
    friend ostream &operator << (ostream &out, const PhanSo &p) {
        out << p.tu << "/" << p.mau;
        return out;
    }
};

int main() {
    int a, b;
    cout << "Nhap p1: ";
    cin >> a >> b;
    PhanSo p1(a, b);
    PhanSo p2;
    cout << "Nhap p2:\n";
    p2.nhap();
    PhanSo p = p1 * p2;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p = p1 * p2 = " << p << endl;

    return 0;
}
