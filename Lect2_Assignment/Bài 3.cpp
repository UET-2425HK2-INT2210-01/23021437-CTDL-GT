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

class doubleLinkedList{
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int p = 0;
    void print(){
        Node* tmp = head;
        while(tmp != nullptr){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    void insert(int x){
        Node* newNode = new Node(x);
        if(p == 0){
            head = newNode;
        }else{
            Node* tmp = head;
            for(int j = 0; j < p-1; j++){
                tmp = tmp->next;
            }
            newNode->prev = tmp;
            newNode->next = tmp->next;
            tmp->next = newNode;
            tail = newNode;
        }
        p++;
    }
    void dem(){
        int count = 0;
        Node* tmp = head;
        tmp = tmp->next;
        while(tmp != tail){
            Node* tmp1 = tmp->prev;
            Node* tmp2 = tmp->next;
            if((tmp->data + tmp1->data + tmp2->data) == 0){
                count++;
            }
            tmp = tmp->next;
        }
        cout << count;
    }
};

int main(){
    int n;
    cin >> n;
    int x;
    doubleLinkedList list;
    for(int i = 0; i < n; i++){
        cin >> x;
        list.insert(x);
    }
    list.dem();
    return 0;
}
