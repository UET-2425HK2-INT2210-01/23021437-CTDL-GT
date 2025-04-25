#include <iostream>
#include <vector>
using namespace std;

// Hàm trộn
void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1; // Lưu số phần tử ở bên trái mảng
    int n2 = right - mid;   // Lưu số phần tử ở bên phải mảng

    vector<int> L(n1), R(n2); // Khởi tạo 2 mảng tạm thời

    // Sao chép mảng
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    // Sắp xếp các phần tử vào đúng vị trí trong mảng theo thứ tự tăng dần
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
            k++;
        }else{
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Sắp xếp nốt các phần tử còn thừa lại trong mảng L[]
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    // Sắp xếp nốt các phần tử còn thừa lại trong mảng R[]
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm sắp xếp trộn
void mergeSort(vector<int>& arr, int left, int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);  // Gọi đệ quy cho mảng bên trái
    mergeSort(arr, mid + 1, right); // Gọi đệ quy cho mảng bên phải
    merge(arr, left, mid, right);   // Gọi hàm trộn
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

    mergeSort(arr, 0, len - 1);

    print(arr);

    return 0;
}
