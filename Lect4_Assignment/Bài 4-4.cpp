#include<iostream>
#include<sstream>
using namespace std;

const int SIZE = 101;

struct Student{
    int id;
    string name;
    string className;
    Student* next;
    Student(int i, string n, string c){
        id = i;
        name = n;
        className = c;
        next = nullptr;
    }
};

class studentManage{
public:
    Student* table[SIZE];
    studentManage(){
        for(int j = 0; j < SIZE; j++){
            table[j] = nullptr;
        }
    }

    int hash_function(int key){
        return key % SIZE;
    }

    void insert(int id, string name, string className){
        int i = hash_function(id);

        Student* newStudent = new Student(id, name, className);

        if(table[i] == nullptr){
            table[i] = newStudent;
        }else{
            Student* tmp = table[i];
            while(tmp->next != nullptr){
                tmp = tmp->next;
            }
            tmp->next = newStudent;
        }
    }

    void remove(int id){
        int i = hash_function(id);
        Student* tmp = table[i];
        Student* prev = table[i];
        do{
            if(tmp->id == id){
                prev->next = tmp->next;
                delete tmp;
            }else{
                prev = tmp;
                tmp = tmp->next;
            }
        }while(tmp != nullptr);
    }

    void search(int id){
        int i = hash_function(id);
        Student* tmp = table[i];
        while(tmp != nullptr){
            if(tmp->id == id){
                break;
            }
            tmp = tmp->next;
        }
        if(tmp != nullptr){
            cout << tmp->name << ", " << tmp->className << endl;
        }else{
            cout << "NA, NA" << endl;
        }
    }
};

int main(){
    int n;
    cin >> n;
    cin.ignore();
    string line;
    int id;
    string name, className;
    char c;
    string operat;

    studentManage student;

    for(int i = 0; i < n; i++){
        getline(cin, line);
        stringstream ss(line);
        ss >> operat;
        if(operat == "Insert("){
            ss >> id >> c >> name >> c >> className >> c;
            student.insert(id, name, className);
        }else if(operat == "Delete("){
            ss >> id >> c;
            student.remove(id);
        }else if(operat == "Search("){
            ss >> id >> c;
            student.search(id);
        }else{
            cout << "invalid";
        }
    }
    return 0;
}

