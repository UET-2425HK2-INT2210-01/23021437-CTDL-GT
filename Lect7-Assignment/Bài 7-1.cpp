#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

//Hàm in
void print(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    return;
}

/*
Giả code bubbleSort:
function bubbleSort(vector v)
    n = size of v
begin:
    for i = 0 -> n - 1
    begin:
        for j = 0 -> n - i - 1
        begin:
            if v[j] > v[j+1]
            swap v[j], v[j+1]
        end if
    end for
end for

*/


//Hàm sắp xếp nổi bọt
void bubbleSort(vector<int> &v){ // Truyền vào mảng tham chiếu
    for(int i = 0; i < v.size() - 1; i++){
    //Sau mỗi vòng lặp i, các phần tử lớn sẽ được sắp xếp dần về cuối mảng
        for(int j = 0; j < v.size() - i - 1; j++){
            // Nếu phần tử trước đó lớn hơn phần tử sau liền kề thì đổi chỗ chúng
            if(v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main(){
    string path;
    cin >> path;
    ifstream fileNumbers(path);
    if(!fileNumbers){
        cout << "Khong tim thay file" << endl;
    }else{
        vector<int> v;
        int x;
        while(fileNumbers >> x){
            v.push_back(x); // Thêm các giá trị trong file vào mảng v
        }
        bubbleSort(v); // Gọi hàm bubbleSort
        print(v); // In ra các giá trị sau khi đã sắp xếp
    }

    return 0;
}
