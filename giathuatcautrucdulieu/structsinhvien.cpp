#include <bits/stdc++.h>
using namespace std;
 struct Sinhvien{
    string msv;
    string ten;
    double gpa;
    string dc;

};
int main(){
    Sinhvien x;
    cin>>x.msv;
    cin.ignore();//xoa phim enter( dung truoc getline de xoa bo nho dem)
    getline(cin, x.ten);
    cin>>x.gpa;
    cin.ignore();
    getline(cin, x.dc);
    cout<<x.msv<<" "<<x.ten<<" "<<fixed<< setprecision(2)<< x.gpa<<" "<<x.dc<<endl;// setprecision dinh dang so chu so sau dau cham( kieu du lieu so thuc)
return 0;
}

