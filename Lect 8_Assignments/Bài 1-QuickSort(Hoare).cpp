#include <iostream>
#include <vector>
using namespace std;

// Hàm phân vùng mảng
int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low]; // Chọn chốt là phần tử đầu

    int i = low - 1;
    int j = high + 1;

    while(true){
        // Tăng chỉ số i cho đến khi tìm thấy phần tử >= chốt
        do{
            i++;
        }while(arr[i] < pivot);
        // Tăng chỉ số j cho đến khi tìm thấy phần tử <= chốt
        do{
            j--;
        }while(arr[j] > pivot);

        if(i >= j) return j; // nếu chỉ số i, j giao nhau thì trả về j

        swap(arr[i], arr[j]); // Hoán đổi 2 phần tử arr[i] và arr[j]
    }
}

// Hàm sắp xếp nhanh
void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high); // Gọi hàm phân vùng mảng
        // pi là chỉ số cuối cùng của phần tử ở mảng bên trái (các phần tử bé hơn hoặc bằng chốt)
        quickSort(arr, low, pi);    // Gọi đệ quy cho mảng bên trái
        quickSort(arr, pi + 1, high);   // Gọi đệ quy cho mảng bên phải
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
