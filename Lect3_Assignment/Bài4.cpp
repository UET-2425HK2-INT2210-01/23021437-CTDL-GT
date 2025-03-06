#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

class Queue{
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

    void enqueue(int x){
        Node* tmp = tail;
        Node* newNode = new Node(x);
        if(tmp == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tmp->next = newNode;
            tail = newNode;
        }
    }

    void dequeue(){
        if(head == nullptr){
            return;
        }else{
            Node* tmp = head;
            head = tmp->next;
            delete tmp;
        }
    }
};

int main(){
    int n;
    cin >> n;
    string operat;
    int x;
    Queue queue;
    for(int i = 1; i <= n; i++){
        cin >> operat;
        if(operat == "enqueue"){
            cin >> x;
            queue.enqueue(x);
        }
        if(operat == "dequeue"){
            queue.dequeue();
        }
    }
    queue.print();
    return 0;
}

/*
    Mã giả:
        Khai báo Node: data và next
        Khai báo Queueu: head = tail = nullptr
        Hàm print():
            tmp = head
            Lặp qua danh sách:
                In tmp->data
                tmp = tmp->next
        Hàm enqueue(x):
            Tạo newNode mới
            Nếu danh sách trống: head = tail = newNode
            Nếu không: tmp = tail, tmp->next = newNode, tail = newNode
        Hàm dequeu():
            tmp = head, head = tmp->next, xóa tmp
        Hàm main():
            Đọc các giá trị n, x, operat
            Lặp n lần:
                Nếu operat = enqueue, gọi hàm enqueue(x)
                Nếu không thì gọi hàm dequeue()
            Gọi print()
    Độ phức tạp (chỉ tính hàm enqueue dequeue): O(1)
    Độ phức tạp (toàn chương trình): O(n)
*/
