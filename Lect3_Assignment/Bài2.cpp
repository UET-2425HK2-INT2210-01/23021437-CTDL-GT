#include<iostream>
using namespace std;

/*double result(int n){
    if(n == 0){
        return 1;
    }else if(n > 0){
        return 2 * result(n-1);
    }else{
        n = -n;
        return 1/(2 * result(n-1));
    }
}

int main(){
    int n;
    cin >> n;
    cout << result(n);
    return 0;
}
*/

/*
    Thuật toán 1:
    Mã giả:
        1.Hàm result(n):
            Nếu n = 0:
                Trả về 1
            Nếu n > 0:
                Trả về 2 * result(n - 1)
            Nếu n < 0:
                Đặt n = -n
                Trả về 1 / (2 * result(n - 1))
        2.Hàm main():
            Đọc giá trị n
            Gọi hàm result(n) và in kết quả
    Độ phức tạp: O(n)
*/


double result(int n){
    if(n == 0){
        return 1;
    }else if(n > 0){
        return (1<<n);
    }else{
        n = -n;
        return (double)1/(1<<n);
    }
}

int main(){
    int n;
    cin >> n;
    cout << result(n);
    return 0;
}

/*
    Thuật toán 2:
    Mã giả:
        1.Hàm result:
            Nếu n = 0, in ra kết quả là 1
            Nếu n > 0, in ra kết quả của 2^n
            Nếu n < 0, in ra kết quả của 1/(2^n)
        2.Hàm main:
            Đọc giá trị n từ bàn phím
            Gọi hàm result(n)
    Độ phức tạp: O(1)
*/
