#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class toado{
    private:
    ll x, y;
    public:
    toado(){};
    toado(ll x, ll y){
        this->x=x;
        this->y=y;
    }
    virtual void nhap(){
        cin >> x >> y;
    }
    virtual void in(){
        cout << x << ' ' << y;
    }
    double distance() const {
        return sqrt(1.0 * x * x + 1.0 * y * y);
    }
};

class diemmau : public toado{
    private:
    int mau;
    public:
    diemmau() : toado(), mau(0) {}
    diemmau(ll x, ll y, int mau) : toado(x, y), mau(mau) {}
    void nhap() override{
        toado::nhap();
        cin >> mau; 
    }
    void in() override{
        toado::in();
        cout <<' ' << mau << endl;
    }
    int getmau() const{
        return mau;
    }
};

int main(){
    int n; cin >>n;
    vector<diemmau> a(n);
    for(int i =0 ;i < n;i++){
        a[i].nhap();
    }
    int count1=0, count2=0, count3=0;
    for(auto &d : a){
        if(d.getmau() == 1){
            ++count1;
        }
        else if(d.getmau()==2){
            ++count2;
        }
        else{
            ++count3;
        }
    }
    cout << "So diem mau do la : " << count1<<endl;
    cout << "So diem mau vang la : " << count2<<endl;
    cout << "So diem mau xanh la : " << count3<<endl;
    int max=-1e9;
    diemmau ans; 
    for(auto &d: a){
        if(d.distance() > max){
            max= d.distance();
            ans = d;
        }
    }
    cout << "Diem xa goc toa do nhat la: " ;
    ans.in();
    return 0;
}