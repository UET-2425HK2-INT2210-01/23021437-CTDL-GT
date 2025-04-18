#include<iostream>
#include<cmath>
using namespace std;

// Hàm tìm ươc chung lớn nhất bằng thuật toán euclid
int getGCD(int x, int y){ // x > y
    if(x % y == 0){ //
        return y; // Nếu số dư x % y = 0 thì trả về y
    }
    return getGCD(y, x % y); // Gọi hàm đệ quy getGCD
}

int main(){
    int x, y;
    cin >> x >> y;

    int u = getGCD(max(x, y), min(x, y));
    cout << u;
    return 0;
}
