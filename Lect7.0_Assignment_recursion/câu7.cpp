#include<iostream>
using namespace std;

// Hàm đảo ngược số nguyên n
int reverseNumbers(int n, int revNum){
    if(n == 0){ // TH cơ sở, n = 0 thì return revNum
        return revNum;
    }
    return reverseNumbers( n / 10, revNum * 10 + (n % 10) ); // Gọi đệ quy đuôi
}

int main(){
    int n;
    cin >> n;
    cout << reverseNumbers(n, 0);
    return 0;
}

