#include<iostream>
using namespace std;

// Hàm tính tổng các chữ số trong 1 số nguyên
int sumNumbers(int n){
    if( n == 0 ){ // TH cơ sở, nếu n = 0 thì return 0
        return 0;
    }
    return (n % 10) + sumNumbers(n / 10); // Gọi đệ quy
}

int main(){
    int n;
    cin >> n;
    cout << sumNumbers(n);
    return 0;
}

