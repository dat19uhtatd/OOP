#include <bits/stdc++.h>
using namespace std;

class MonHoc {
private:
    int ma, sotin;
    string ten;

public:
    MonHoc() : ma(0), sotin(0), ten("") {}

    MonHoc(int ma, int sotin, string ten)
        : ma(ma), sotin(sotin), ten(ten) {}

    void nhap() {
        cout << "Nhap ma mon: ";
        cin >> ma;
        cin.ignore();
        cout << "Nhap ten mon: ";
        getline(cin, ten);
        cout << "Nhap so tin chi: ";
        cin >> sotin;
    }

    void in() const {
        cout << "Ma mon: " << ma << " | Ten: " << ten << " | Tin chi: " << sotin << endl;
    }

    int getMa() const { return ma; }
    int getTin() const { return sotin; }
    string getTen() const { return ten; }
};

class DKHP {
private:
    string masv;
    string hoten;        
    vector<int> ds_mon;

public:
    DKHP() {}
    void nhap() {
        cout << "\nNhap ma sinh vien: ";
        cin >> masv;
        cin.ignore();
        cout << "Nhap ho ten sinh vien: ";
        getline(cin, hoten);   
        int k;
        cout << "So mon dang ky: ";
        cin >> k;
        cout << "Nhap cac ma mon: ";
        ds_mon.resize(k);
        for (int i = 0; i < k; i++) {
            cin >> ds_mon[i];
        }
    }

    void in() {
        cout << "Ma SV: " << masv 
             << " | Ten: " << hoten 
             << " | So mon: " << ds_mon.size() << endl;
    }
    string getSV() const { return masv; }
    string getTen() const { return hoten; }     
    const vector<int>& getDS() const { return ds_mon; }
};


int main() {
    int m;
    cout << "Nhap so mon hoc: ";
    cin >> m;
    vector<MonHoc> dsMon(m);
    cout << "\n=== Nhap danh sach mon hoc ===\n";
    for (int i = 0; i < m; i++) {
        cout << "\nMon thu " << i + 1 << ":\n";
        dsMon[i].nhap();
    }
    int n;
    cout << "\nNhap so sinh vien dang ky hoc phan: ";
    cin >> n;
    vector<DKHP> dsDK(n);
    cout << "\n=== Nhap danh sach DKHP ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nSinh vien thu " << i + 1 << ":\n";
        dsDK[i].nhap();
    }
    cout << "\n=== Tong so tin chi moi sinh vien ===\n";
    for (auto &dk : dsDK) {
        int tongtin = 0;
        for (int maMon : dk.getDS()) {
            for (auto &mh : dsMon) {
                if (mh.getMa() == maMon) {
                    tongtin += mh.getTin();
                }
            }
        }
        cout << "Sinh vien " << dk.getSV() << " dang ky " << tongtin << " tin chi.\n";
    }
    // 2. Nhập 1 mã môn và cho biết sinh viên đăng ký môn đó
    int maTim;
    cout << "\nNhap ma mon can tim sinh vien dang ky: ";
    cin >> maTim;
    cout << "Sinh vien dang ky mon " << maTim << ":\n";
    bool found = false;
    for (auto &dk : dsDK) {
        for (int maMon : dk.getDS()) {
            if (maMon == maTim) {
                cout << dk.getSV() << "\n";
                found = true;
                break;
            }
        }
    }
    if (!found) cout << "Khong co sinh vien nao dang ky mon nay.\n";
    return 0;
}
