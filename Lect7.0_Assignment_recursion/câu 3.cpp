#include<iostream>
using namespace std;

// Hàm tìm số fibonacci thứ n
int fibonacci(int n){
    if(n == 0){ // TH cơ sở, n = 0 thì return 0
        return 0;
    }
    if(n == 1){ // TH cơ sở, n = 1 thì return 1
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Gọi đệ quy
}

int main(){
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
