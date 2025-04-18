#include<iostream>
using namespace std;

// Hàm tính giai thừa
long long factorial(int n){
    if(n == 1 || n == 0){ // TH cơ sở, n = 0 | n= 1 thì return 1
        return 1;
    }
    return n * factorial(n - 1); // Gọi đệ quy
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}
