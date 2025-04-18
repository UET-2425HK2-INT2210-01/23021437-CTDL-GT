#include<iostream>
#include<vector>
using namespace std;

// Hàm in ra các giá trị binary thỏa mãn
void print(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
    }
    cout << endl;
    return;
}

// Hàm sinh số binary
void generateBinary(int n, int count, vector<int> v){ // Truyền vào các đối số
    if(count == n){ // TH cơ sở: nếu count = n thì return;
        return;
    }
    for(int i = 0; i <= 1; i++){
        if(count < n){ // Nếu count < n
            count++;    // Tăng biến đếm count thêm 1
            v.push_back(i); // Thêm phần tử i vào mảng
            generateBinary(n, count, v); // Gọi hàm đệ quy
            if(count == n){
                print(v); // Nếu count = n thì in ra kết quả
            }
            v.pop_back(); // Xóa đi phần tử cuối cùng
            count--; // Giảm biến đếm đi 1
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    generateBinary(n, 0, v);
    return 0;
}
