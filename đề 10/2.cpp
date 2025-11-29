#include <bits/stdc++.h>
using namespace std;

class mathang
{
private:
    int ma, soluong, gia;
    string ten, nhasanxuat;

public:
    mathang() : ma(0), soluong(0), gia(0), ten(""), nhasanxuat("") {}

    mathang(int ma, int soluong, int gia, string ten, string nhasanxuat)
        : ma(ma), soluong(soluong), gia(gia), ten(ten), nhasanxuat(nhasanxuat) {}

    virtual void nhap()
    {
        cout << "Nhap ma hang: ";
        cin >> ma;
        cin.ignore(); // tránh lỗi getline
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap nha san xuat: ";
        getline(cin, nhasanxuat);
        cout << "Nhap so luong: ";
        cin >> soluong;
        cout << "Nhap don gia: ";
        cin >> gia;
    }

    virtual void in()
    {
        cout << "Ma hang: " << ma << "\n";
        cout << "Ten: " << ten << "\n";
        cout << "Nha san xuat: " << nhasanxuat << "\n";
        cout << "So luong: " << soluong << "\n";
        cout << "Gia: " << gia << "\n";
    }
    int getmahang()  const {
        return ma;
    }
    int getgia() const{
        return gia;
    }
};

class maytinh : public mathang
{
private:
    string cpu, hedieuhanh;
    int trongluong;

public:
    maytinh()
        : mathang(), cpu(""), hedieuhanh(""), trongluong(0) {}

    maytinh(int ma, int soluong, int gia, string ten, string nhasanxuat,
            string cpu, string hedieuhanh, int trongluong)
        : mathang(ma, soluong, gia, ten, nhasanxuat),
          cpu(cpu),                        // ⭐ thêm dòng này
          hedieuhanh(hedieuhanh),
          trongluong(trongluong)
    {
    }

    void nhap() override
    {
        mathang::nhap();
        cout << "Nhap CPU: ";
        cin >> cpu;
        cout << "Nhap he dieu hanh: ";
        cin >> hedieuhanh;
        cout << "Nhap trong luong: ";
        cin >> trongluong;
    }

    void in() override
    {
        mathang::in();
        cout << "CPU: " << cpu << "\n";
        cout << "He dieu hanh: " << hedieuhanh << "\n";
        cout << "Trong luong: " << trongluong << "g\n";
    }
};

int main(){
    int n; cin >> n;
    vector<maytinh> a(n);
    for(int i=0; i< n; i++){
        a[i].nhap();
    }
    int x; 
    cout << "Nhap ma may : ";
    cin >> x;
    int found =0;
    maytinh ans;
    for(auto &d : a){
        if(d.getmahang() == x){
            found=1;
            ans = d;
        }
    }
    if(found){
        ans.in();
    }
    else{
        cout << "Khong tim thay ma may nay trong danh sach";
    }
    int max=-1e9;
    maytinh y;
    cout << "\n";
    for(auto &d  : a){
        if(d.getgia() > max){
            y = d;
        }
    }
    cout << "May co gia cao nhat la : \n";
    y.in();
}
