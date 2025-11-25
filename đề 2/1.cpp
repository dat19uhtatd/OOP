#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class diem{
private:
    ll hoanh, tung;
public:
    diem(){};
    diem(ll hoanh, ll tung){
        this->hoanh=hoanh;
        this->tung=tung;
    }
    friend istream &operator >> (istream &in, diem &d){
        in >> d.hoanh >> d.tung;
        return in;
    }
    friend ostream &operator << (ostream &out, diem d){
        out << d.hoanh << ' ' << d.tung;
        return out;
    }
    double distance() const {
        return sqrt(1.0 * hoanh * hoanh + 1.0 * tung * tung);
    }
};

int main(){
    int n; cin >> n;
    vector<diem> a(n);
    for(int i = 0; i< n ; i++){
        cin >> a[i];
    }
    double tong=0;
    for(auto &d : a){
        tong+= d.distance();
    }
    cout << fixed << setprecision(2) << tong;
    int min=1e9;
    diem ans;
    for(auto &d : a){
        if(d.distance() < min){
            min = d.distance();
            ans = d;
        }
    }
    cout << "Diem gan goc toa do nhat" << ans << endl;
}