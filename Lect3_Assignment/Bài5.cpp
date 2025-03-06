#include<iostream>
using namespace std;

const int MAX = 1000;
int n = 0, stack[MAX];

void print(){
    for(int i = 0; i < n; i++){
        cout << stack[i] << " ";
    }
    return;
}

void push(int x){
    if(n == MAX){return;}
    stack[n] = x;
    n++;
}
void pop(){
    if(n == 0){return;}
    n--;
}

int main(){
    int n;
    cin >> n;
    int x;
    string operat;
    for(int i = 1; i <=n; i++){
        cin >> operat;
        if(operat == "push"){
            cin >> x;
            push(x);
        }else{
            pop();
        }
    }
    print();
    return 0;
}

/*
    Mã giả:
        Khởi tạo MAX = 1000, n = 0, mảng stack[MAX]
    Hàm print():
        In ra các phần tử của mảng stack
    Hàm push(x):
        Nếu n = MAX thì return
        Nếu n < MAX, gán push[n] = x, rồi tăng n thêm 1
    Hàm pop():
        Nếu n == 0 thì return
        Nếu n > 0 thì giảm n đi 1
    Hàm main():
        Đọc các giá trị n, x, operat
        Lặp n lần:
            Nếu operat = push, gọi hàm push(x)
            Nếu không thì gọi hàm pop()
        In ra giá trị của mảng

    Độ phức tạp (chỉ tính hàm push và pop): O(1)
*/
