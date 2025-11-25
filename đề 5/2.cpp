#include <bits/stdc++.h>
using namespace std;

class ngaythang{
private:
    int d, m , y;
public:
    ngaythang(){};
    void nhap(){
        cin >> d >> m >> y;
    }
    void in() const {
        cout << d << "/" << m << "/" << y;
    }
};

class nguoi{
protected:
    string ten;
    ngaythang ngaysinh; 
    string diachi;
public:
    nguoi(){};
    virtual void nhap(){;
        cout << "Nhap ho ten : ";
        cin.ignore();
        getline(cin , ten);
        cout << "Nhap ngay sinh (d m y): ";
        ngaysinh.nhap();
        cin.ignore();
        cout << "Nhap dia chi : ";
        getline(cin , diachi);
        
    }
    virtual void in() const {
        cout << "Ten : " << ten << endl;
        cout << "Ngay sinh : ";
        ngaysinh.in();
        cout << "\nDia chi : " << diachi << endl;
    }
    string getten() const{
        return ten;
    }
};

class khachhang : public nguoi{
private:
    int ma, chisotruoc , chisosau;
public:
    khachhang(){
        ma = chisotruoc = chisosau = 0;
    }

    khachhang(int ma, string ten, ngaythang ngaysinh, string diachi,
              int chisotruoc, int chisosau)
    {
        this->ma = ma;
        this->ten = ten;
        this->ngaysinh = ngaysinh;
        this->diachi = diachi;
        this->chisotruoc = chisotruoc;
        this->chisosau = chisosau;
    }

    void nhap() override{
        cout << "Nhap ma: ";
        cin >> ma;
        nguoi::nhap();
        cout << "Nhap chi so truoc : ";
        cin >> chisotruoc;
        cout << "Nhap chi so sau : ";
        cin >> chisosau;
    }

    void in() const override{
        cout <<"Ma : " << ma << endl;
        nguoi::in();
        cout << "Chi so truoc : " << chisotruoc << endl;
        cout << "Chi so sau : " << chisosau << endl;
        int sd = tieuthu();
        cout << "So dien da su dung : " << sd << " kWh" << endl;
        cout << "Tien dien : " << fixed << setprecision(2) << tinhTien() << " VND" << endl;
    }

    int tieuthu() const {
        return chisosau - chisotruoc;
    }

    int bacDien() const {
        int sd = tieuthu();
        if (sd <= 50) return 1;
        if (sd <= 100) return 2;
        if (sd <= 200) return 3;
        if (sd <= 300) return 4;
        return 5;
    }

    double tinhTien() const {
        int sd = tieuthu();
        double sum = 0;
        if (sd <= 0) return 0;
        int bac[5] = {50, 50, 50, 100, 100};
        double gia[5] = {1.678, 1.734, 2.014, 2.536, 2.834};
        for (int i = 0; i < 5 && sd > 0; i++) {
            int use = min(sd, bac[i]);
            sum += use * gia[i];
            sd -= use;
        }
        return sum;
    }
};

int main(){
    int n; 
    cout << "Nhap so luong khach hang: ";
    cin >> n;

    vector<khachhang> a(n);

    for(int i=0; i< n;i++){
        cout << "\n--- Khach hang " << i+1 << " ---\n";
        a[i].nhap();
    }
    cin.ignore();
    string x;
    cout << "\nNhap ho ten can tim: ";
    getline(cin, x);
    bool found = false;
    for (auto &d : a) {
        if (d.getten() == x) {
            cout << "\n== THONG TIN KHACH HANG ==\n";
            d.in();
            found = true;
            break;
        }
    }
    if (!found) cout << "Khong tim thay!\n";
    int dem[6] = {0};
    for (auto &kh : a) dem[kh.bacDien()]++;

    cout << "\n=== THONG KE THEO BAC DIEN ===\n";
    for (int i = 1; i <= 5; i++) {
        cout << "Bac " << i << ": " << dem[i] << " khach\n";
    }
    int tongDien = 0;
    double tongTien = 0;
    for (auto &kh : a) {
        tongDien += kh.tieuthu();
        tongTien += kh.tinhTien();
    }
    cout << "\nTong so dien da su dung: " << tongDien << " kWh\n";
    cout << "Tong tien dien: " << fixed << setprecision(2) << tongTien << " VND\n";

    return 0;
}
