#include<iostream>
using namespace std;

// Hàm tính lũy thừa x ^ n
int luyThua(int x, int n){
    if(n == 0){ // TH cơ sở, n = 0 thì return 1
        return 1;
    }
    return x * luyThua(x, n - 1); // Gọi đệ quy
}

int main(){
    int x, n;
    cin >> x >> n;
    cout << luyThua(x, n);
    return 0;
}
