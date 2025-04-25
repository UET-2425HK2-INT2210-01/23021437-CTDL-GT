#include <iostream>
#include <vector>
using namespace std;

// Hàm phân vùng mảng
int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high]; // Chọn phần tử cuối làm chốt

    int i = low - 1;

    for(int j = low; j < high; j++){
        // Nếu phần tử hiện tại nhỏ hơn pivot thì tăng i thêm 1 và hoán đổi arr[i] và arr[j]
        // Các phần tử nhỏ hơn chốt sẽ được đẩy về phía bên trái
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);    // Hoán đổi arr[i+1] và phần tử cuối của mảng

    return i + 1;
}

// Hàm sắp xếp nhanh
void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high); // Gọi hàm phân vùng mảng
        quickSort(arr, low, pi - 1);    // Gọi đệ quy cho mảng bên phải
        quickSort(arr, pi + 1, high);   // Gọi đệ quy cho mảng bên trái
    }
}

void print(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int len;
    cin >> len;
    vector<int> arr(len);
    for(int i = 0; i < len; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, len - 1);
    print(arr);
    return 0;
}
