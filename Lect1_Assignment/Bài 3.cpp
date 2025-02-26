#include<iostream>
using namespace std;

int main(){
    int num1, num2;
    cin >> num1 >> num2;
    int r = num1 % num2;
    if(r == 0){
        cout << num2;
        return 0;
    }else{
        while(r != 0){
            num1 = num2;
            num2 = r;
            r = num1 % num2;
        }
    }
    cout << num2;
    return 0;
}
