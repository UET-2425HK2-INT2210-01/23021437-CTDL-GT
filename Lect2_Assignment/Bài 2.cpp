#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

struct LinkedList{

    Node *head = nullptr;
    int len = 0;

    void print(){
        Node *tmp = head;
        while(tmp != nullptr){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    void insert(int p, int x){
        if(p < 0 || p > len){
            cout << "invalid";
            return;
        }
        Node* newNode = new Node(x);
        if(p == 0){
            newNode->next = head;
            head = newNode;
        }else{
            Node* tmp = head;
            for(int i = 0; i < p-1; i++){
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
        len++;
    }

    void del(int p){
        if(p < 0 || p >= len || head == nullptr){
            cout << "invalid";
            return;
        }
        Node* tmp = head;
        if(p == 0){
            head = head->next;
            delete tmp;
        }else{
            Node *prev = nullptr;
            for(int i = 0; i < p; i++){
                prev = tmp;
                tmp = tmp->next;
            }
            prev->next = tmp->next;
            delete tmp;
        }
        len--;
    }
};

int main(){
    int n;
    cin >> n;
    LinkedList List;
    for(int i = 0; i < n; i++){
        string op;
        cin >> op;
        if(op == "insert"){
            int p, x;
            cin >> p >> x;
            List.insert(p, x);
        }else if(op == "delete"){
            int p;
            cin >> p;
            List.del(p);
        }
    }
    List.print();
    return 0;
}
