#include<iostream>
using namespace std;

const int MAX = 1000;
int n = 0, queue[MAX];

void print(){
    for(int i = 0; i < n; i++){
        cout << queue[i] << " ";
    }
    return;
}

void enqueue(int x){
    if(n == MAX){return;}
    queue[n] = x;
    n++;
}

void dequeue(){
    if(n == 0){return;}
    for(int i = 0; i < n; i++){
        queue[i] = queue[i+1];
    }
    n--;
}

int main(){
    int n;
    cin >> n;
    int x;
    string operat;
    for(int i = 1; i <=n; i++){
        cin >> operat;
        if(operat == "enqueue"){
            cin >> x;
            enqueue(x);
        }
        if(operat == "dequeue"){
            dequeue();
        }
    }
    print();
    return 0;
}

/*
    Mã giả:
    Khởi tạo MAX = 1000, n = 0, mảng queue[MAX]
    Hàm print():
        In ra các phần tử của mảng queue
    Hàm enqueue(x):
        Nếu n = MAX thì return
        Nếu n < MAX, gán queue[n] = x, rồi tăng n thêm 1
    Hàm dequeue():
        Nếu n == 0 thì return
        Nếu n > 0, gán giá trị của phần tử trước cho phần tử kế tiếp, bắt đầu từ phần tử đầu tiên, sau đó giảm n đi 1
    Hàm main():
        Đọc các giá trị n, x, operat
        Lặp n lần:
            Nếu operat = enqueue, gọi hàm enqueue(x)
            Nếu không thì gọi hàm dequeue()
        In ra giá trị của mảng
    Độ phức tạp (chỉ tính enqueuu và dequeue): O(n)
*/

