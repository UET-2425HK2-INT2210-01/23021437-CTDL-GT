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

// Hàm kiểm tra các chữ số trong 1 số có khác nhau không
bool isValid(vector<int> v){
    for(int i = 0; i < v.size() - 1; i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v[i] == v[j]) return false; // Nếu có chữ số giống nhau thì trả về false
        }
    }
    return true; // Nếu không trả về true
}

// Hàm sinh hoán vị của số
void generateNumbers(int n, int count, vector<int> v){ // Truyền vào các đối số
    if(count == n){ // TH cơ sở: nếu count = n thì return;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(count < n){ // Nếu count < n
            count++;    // Tăng biến đếm count thêm 1
            v.push_back(i); // Thêm phần tử i vào mảng
            generateNumbers(n, count, v); // Gọi hàm đệ quy
            if(count == n && isValid(v)){
                print(v); // Nếu count = n và các chữ số của hoán vị khác nhau thì in ra kết quả
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
    generateNumbers(n, 0, v);
    return 0;
}
