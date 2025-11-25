#include <bits/stdc++.h>
using namespace std;

class thisinh{
    private:
    string ten;
    double diem;
    public:
    thisinh(){};
    thisinh(string ten, double diem) : ten(ten), diem(diem) {}
    virtual void nhap(){
        cin >> ten >> diem;
    }
    virtual void in(){
        cout << "Thong tin thi sinh : " << ten << diem << endl;
    }
    double getdiem(){
        return diem;
    }
};

class olympic : public thisinh{
    private:
    string truong;
    public:
    olympic() : thisinh(), truong("") {}

    olympic(string ten, double diem, string truong) 
        : thisinh(ten, diem) {
            this->truong;
        }
    void nhap() override {
        thisinh::nhap();
        cin >> truong;
    }
    void in() override{
        thisinh::in();
        cout << truong << endl;
    }
    string gettruong() const{
        return truong;
    }
};

int main(){
    int n;
    cout << "Nhap so luong thi sinh : ";
    cin >> n;
    vector<olympic> a(n);
    for(int i=0; i<n;i++){
        a[i].nhap();
    }
    long long d1 =0, d2 =0, d3 =0;
    for(auto &d : a){
        if(d.gettruong() == "A"){
            d1+=d.getdiem();
        }
        else if(d.gettruong() == "B"){
            d2+=d.getdiem();
        }
        else{
            d3+=d.getdiem();
        }
    }
    cout << "Tong diem truong A la: " << d1 << endl;
    cout << "Tong diem truong B la: " << d2 << endl;
    cout << "Tong diem truong C la: " << d3 << endl;
    int max =-1e9;
    if (d1 >= d2 && d1 >= d3) {
        max = d1;
    } else if (d2 >= d1 && d2 >= d3) {
        max = d2;
    } else {
        max = d3;
    }
    cout << "Truong co diem cao nhat la: "<<endl;
    if(d1 == max){
        cout << "Truong A co tong diem cao nhat" << endl;
    }
    if(d2 == max){
        cout << "Truong B co tong diem cao nhat" << endl;
    }
    if(d3 == max){
        cout << "Truong C co tong diem cao nhat"<< endl;
    }
    int cnt1=0, cnt2=0, cnt3=0;
    for(auto &d : a){
        if(d.gettruong() == "A"){
            ++cnt1;
        }
        if(d.gettruong() == "B"){
            ++cnt2;
        }
        if(d.gettruong() == "C"){
            ++cnt3;
        }
    }
    cout << "So luong thi sinh truong A la : " << cnt1 << endl;
    cout << "So luong thi sinh truong B la : " << cnt2 << endl;
    cout << "So luong thi sinh truong C la : " << cnt3 << endl;
}