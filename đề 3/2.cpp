#include <bits/stdc++.h>
using namespace std;

class hang{
    private:
    int ma, gia, soluong;
    string ten;
    public:
    hang(){};
    hang(int ma, int gia , int soluong , string ten){
        this->ten=ten;
        this->ma=ma;
        this->soluong=soluong;
        this->gia=gia;
    }
    virtual void nhap(){
        cin >> ma >> ten >> gia >> soluong;
    }
    virtual void in(){
        cout << ma << ' ' << ten << ' ' << gia << ' ' << soluong<< ' ' ;
    }
    int getma() const {
        return ma;
    }
    string getten() const{
        return ten;
    }
    int getgia() const{
        return gia;
    }
};

class maygiat : public hang{
    private:
    int socan;
    public:
    maygiat() : hang(), socan(0) {}
    maygiat(int ma, string ten, int gia, int soluong, int socan) 
    : hang(ma, gia, soluong, ten) {
    this->socan = socan;
    }
    void nhap() override{
        hang::nhap();
        cin >> socan;
    }
    void in() override{
        hang::in();
        cout << socan << endl;
    }
    int getcan() const{
        return socan;
    }
};

int main(){
    int n ; cin >> n;
    vector<maygiat> a(n);
    for(int i =0; i< n;i++){
        a[i].nhap();
    }
    cout << "Nhap ma hang can tim: ";
    int ma; cin >> ma;
    for(auto &d : a){
        if(d.getma() == ma){
            d.in();
        }
    }
    int min =1e9;
    maygiat ans;
    for(auto &d : a){
        if(d.getcan() > 6 && d.getgia() < min ){
            ans = d;
        }
    }
    cout << "\nThong tin may giat: " ;
    ans.in();
}