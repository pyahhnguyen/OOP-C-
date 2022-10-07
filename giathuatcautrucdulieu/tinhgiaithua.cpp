#include <iostream>
using namespace std;
int giaiThua(int n)
{
    if (n == 1)
        return 1;
        else
    return n * giaiThua(n - 1);
}
int main()
{
    int n;
    cout<<"Nhap n=";
    cin >> n;
    cout <<  n << " giai thua bang : " << giaiThua(n);
    return 0;
}