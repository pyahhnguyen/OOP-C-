#include<iostream>
using namespace std;

int fibonacci(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
 

int main() {
 int i;
    cout << "100 so dau tien cua day so Fibonacci: \n";
        for (i = 0; i < 100; i++) {
        cout << fibonacci(i) << "  ";
    }
}