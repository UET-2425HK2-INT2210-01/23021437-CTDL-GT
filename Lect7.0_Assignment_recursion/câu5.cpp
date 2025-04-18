#include<iostream>
using namespace std;

// Hàm đếm số chữ số trong 1 số nguyên
int countNumbers(int n, int count){
    // Gán r = phần nguyên của n / 10
    int r = n / 10;
    if(r == 0){     // TH cơ sở, r = 0 thì return count
        return count;
    }
    return countNumbers(r, count + 1); // Gọi đệ quy đuôi
}

int main(){
    int n;
    cin >> n;
    cout << countNumbers(n, 1);
    return 0;
}

