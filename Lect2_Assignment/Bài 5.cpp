#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int x){
        data = x;
        prev = nullptr;
        next = nullptr;
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
    }

    void push(int x){
        Node* newNode = new Node(x);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            Node* tmp = tail;
            tmp->next = newNode;
            tail = newNode;
            tail->prev = tmp;
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
        }else{
            stack.pop();
        }
    }
    stack.print();
    return 0;
}
