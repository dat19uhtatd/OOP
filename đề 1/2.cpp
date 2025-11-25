#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class QLH {
protected:
    string ma, ten, xuatxu;
    ll loaihang;  
    ll soluong;

public:
    QLH() {}
    virtual void nhap() {
        cin >> ma;
        cin.ignore();
        getline(cin, ten);
        getline(cin, xuatxu);
        cin >> loaihang >> soluong;
    }
    virtual void xuat() {
        cout << ma << " | " << ten << " | " << xuatxu
             << " | Loai: " << loaihang
             << " | SL: " << soluong;
    }
    ll getLoai() const { return loaihang; }
    ll getSoLuong() const { return soluong; }
};

class DIENTU : public QLH {
private:
    ll tgbh;   
public:
    DIENTU() {}

    void nhap() override {
        QLH::nhap();
        cin >> tgbh;
    }

    void xuat() override {
        QLH::xuat();
        cout << " | Bao hanh: " << tgbh << endl;
    }

    ll getBH() const { return tgbh; }
};

int main() {
    int n;
    cin >> n;
    vector<DIENTU> a(n);
    for (int i = 0; i < n; i++) {
        a[i].nhap();
    }
    ll tong1 = 0, tong2 = 0, tong3 = 0;

    for (auto &d : a) {
        if (d.getLoai() == 1) tong1 += d.getSoLuong();
        else if (d.getLoai() == 2) tong2 += d.getSoLuong();
        else tong3 += d.getSoLuong();
    }

    cout << "Tong so luong hang loai 1: " << tong1 << endl;
    cout << "Tong so luong hang loai 2: " << tong2 << endl;
    cout << "Tong so luong hang loai 3: " << tong3 << endl;
    ll maxBH = -1;
    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (a[i].getLoai() == 1 && a[i].getBH() > maxBH) {
            maxBH = a[i].getBH();
            pos = i;
        }
    }

    cout << "\nMat hang dien tu loai 1 co bao hanh lau nhat:\n";
    if (pos != -1)
        a[pos].xuat();
    else
        cout << "Khong co mat hang loai 1 nao!\n";

    return 0;
}
