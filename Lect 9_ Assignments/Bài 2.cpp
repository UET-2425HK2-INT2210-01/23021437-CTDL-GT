#include <iostream>
#include <vector>
using namespace std;

// Hàm kiểm tra xem có tổng con không
bool subSum(vector<int>& arr, int X){
    int n = arr.size(); // Kích thước mảng

    // Khởi tạo mảng 2 chiều có kích thước n+1 x X+1 với tất cả giá trị ban đầu bằng false
    vector<vector<int>> dp(n + 1, vector<int>(X + 1, false));

    for(int i = 0; i <= n; i++){
        dp[i][0] = true; // Phần tử đầu tiên ở mỗi cột bằng 0
    }

    // Điền bảng quy hoạch động
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= X; j++){
            // Nếu j(tổng) < phần tử hiện tại thì không chọn dp[i][j]
            if(j < arr[i - 1]){
                dp[i][j] = dp[i - 1][j];
            }
            // Ngược lại thì có thể chọn hoặc không chọn dp[i][j]
            else{
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][X]; // Trả lại giá trị cuối cùng của bảng
}

int main(){
    int n, X;
    cin >> n >> X;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if( subSum(arr, X) ){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}
