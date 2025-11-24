#include <bits/stdc++.h>
using namespace std;

class phanso
{
private:
    int tu, mau;
public:
    phanso() {};
    phanso(int tu, int mau)
    {
        this->tu = tu;
        this->mau = mau;
    }
    friend istream &operator>>(istream &in, phanso &p)
    {
        in >> p.tu >> p.mau;
        return in;
    }
    friend ostream &operator<<(ostream &out, phanso p)
    {
        out << p.tu << "/" << p.mau << endl;
        return out;
    }
     static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    friend phanso operator+(phanso p1, phanso p2)
    {
        phanso res;
        res.tu = p1.tu * p2.mau + p2.tu * p1.mau;
        res.mau = p1.mau * p2.mau;
        int g = gcd(abs(res.tu), abs(res.mau));
        res.tu /= g;
        res.mau /= g;
        return res;
    }
};

int main(){
    phanso p1, p2;
    cin >> p1 >> p2;
    cout << p1 << p2;
    cout << p1 + p2 << endl;
}