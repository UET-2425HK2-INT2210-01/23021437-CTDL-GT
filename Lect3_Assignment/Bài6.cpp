#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Stack{
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void print(){
        Node* tmp = head;
        while(tmp != nullptr){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
        return;
    }

    void push(int x){
        Node* newNode = new Node(x);
        Node* tmp = tail;
        if(tmp == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            newNode->prev = tmp;
            tmp->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        Node* tmp = tail;
        if(tmp == nullptr){
            return;
        }else{
            tail = tmp->prev;
            tail->next = tmp->next;
            delete tmp;
        }
    }
};

int main(){
    int n;
    cin >> n;
    string operat;
    int x;
    Stack stack;
    for(int i = 1; i <= n; i++){
        cin >> operat;
        if(operat == "push"){
            cin >> x;
            stack.push(x);
        }
        if(operat == "pop"){
            stack.pop();
        }
    }
    stack.print();
    return 0;
}

/*
    Mã giả:
        Khai báo Node: data, next và prev
        Khai báo Stack: head = tail = nullptr
        Hàm print():
            tmp = head, lặp qua danh sách và in ra tmp->data
            tmp = tmp->next
        Hàm push(x):
            Nếu danh sách trống: head = tail = newNode
            Nếu không: tmp = tail, newNode->prev = tmp, tmp->next = newNode, tail = newNode
        Hàm pop():
            tmp = tail, tail = tmp->prev, xóa tmp
        Hàm main():
            Đọc các giá trị n, x operat
            Lặp n lần:
                Nếu operat = push, gọi hàm push(x)
                Nếu không thì gọi hàm pop()
            Gọi hàm print()
    Độ phức tạp thuật toán (chỉ tính riêng hàm push và pop): O(1)
    Độ phức tạp thuật toán (toàn chương trình): O(n)
*/
