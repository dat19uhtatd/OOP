#include <bits/stdc++.h>
using namespace std;

class hcn{
    private:
    long long x, y;
    public:
    hcn(){};
    hcn(long long x, long long y){
        this->x=x;
        this->y=y;
    }
    void nhap(){
        cout <<"Nhap chieu dai: ";
        cin >> x;
        cout << "Nhap chieu rong: ";
        cin >> y;
    }
    void in(){
        cout << "Hinh chu nhat cos CD CR : " << x << ' ' << y << endl;
    }
    long long dientich(){
        return x * y;
    }
};

int main(){
    int n; cin >> n;
    vector<hcn> a(n);
    for(int i =0 ;i<n;i++){
        a[i].nhap();
    }
    long long tong=0, cnt=0;
    for(auto &d : a){
        tong += d.dientich();
        ++cnt;
    }
    cout << "dien tich trung binh : "<< tong/cnt << endl;
    int min =1e9;
    for(auto &d :a){
        if(d.dientich() < min ){
            min= d.dientich();
        }
    }
    cout << "Nhung hinh co dien tich nho nhat : \n";
    for(auto &d : a){
        if(d.dientich() == min){
            d.in();
        }
    }
}