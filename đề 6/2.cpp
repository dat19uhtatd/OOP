#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class mathang{
    private:
    string ma, ngayban;
    int gia;
    public:
    mathang(){};
    mathang(string ma , string ngayban , int gia){
        this->ma= ma;
        this->ngayban = ngayban;
        this->gia=gia;
    }
    virtual void nhap(){
        cout << "Nhap ma: ";
        getline(cin , ma);
        cout << "Nhap ngay ban: " ;
        getline(cin , ngayban);
        cout << "Nhap gia : ";
        cin >> gia;
    }
    virtual void in(){
        cout << "Ma :" << ma << endl;
        cout <<"Ngay ban : " << ngayban << endl;
        cout << "Gia : " << gia << endl;
    }
    int getgia() const{
        return gia;
    }
    string getngayban() const{
        return ngayban;
    }
};

class hoadon : public mathang{
    private:
    int soluong;
    public:
    hoadon() : mathang() , soluong(0){};
    hoadon(string ma , int soluong , string ngayban , int gia) : 
    mathang(ma , ngayban , gia){
        this->soluong = soluong;
    }
    void nhap() override{
        cin.ignore();
        mathang::nhap();
        cout << "Nhap so luong : ";
        cin >> soluong;
    }
    void in() override{
        mathang::in();
        cout <<"So luong : "<< soluong  << endl;
    }
    int getsoluong() const {
        return soluong;
    }
};

int main(){
    int n; cin >> n;
    vector<hoadon> a(n);
    for(int i=0; i<n ;i++){
        a[i].nhap();
    }
    for(auto &d : a){
        if(d.getsoluong() > 10){
            d.in();
        }
    }
    string ngay;
    cout << "Nhap ngay ban : ";
    cin >> ngay;
    int tong=0;
    for(auto &d : a){
        if(d.getngayban() == ngay){
            tong += d.getsoluong() * d.getgia();
        }
    }
    cout << "So tien ban duoc trong mot ngay la : " << tong << endl;
}