#include<iostream>
#include<string>
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

    void print(){
        Node* tmp = head;
        while(tmp != nullptr){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void enqueue(int x){
        Node* newNode = new Node(x);
        Node* tmp = head;
        if(tmp == nullptr){
            head = newNode;
        }else{
            while(tmp->next != nullptr){
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
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
        }else{
            queue.dequeue();
        }
    }
    queue.print();
    return 0;
}
