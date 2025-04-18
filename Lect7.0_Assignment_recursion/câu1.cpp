#include<iostream>
using namespace std;

// Hàm tính tổng từ 1 -> n
int sum(int n){
    if(n == 1){ // TH cơ sở: n = 1 thì return 1
        return 1;
    }
    return n + sum(n - 1); // Gọi đệ quy
}

int main(){
    int n;
    cin >> n;
    cout << sum(n);
    return 0;
}
