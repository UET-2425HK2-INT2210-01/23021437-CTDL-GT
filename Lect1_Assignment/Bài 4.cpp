#include<iostream>
using namespace std;

void Sort(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            if(a[j] < a[j-1]){
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Sort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
