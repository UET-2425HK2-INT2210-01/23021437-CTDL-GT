#include <iostream>
#include <vector>
using namespace std;

int maxSumValues(vector<int>& w, vector<int>& v, int X, int n){
    // Khởi tạo mảng 2 chiều kích thước n+1 x X+1
    vector<vector<int>> dp(n + 1, vector<int>(X + 1));

    // Điền bảng quy hoạch động
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= X; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0; // Không có đồ vật để chọn hay sức chứa balo bằng 0
            }else{
                int pick = 0;
                if(j >= w[i - 1]){
                    // Chọn vật i nếu không vượt quá sức chứa balo
                    pick = v[i - 1] + dp[i - 1][j - w[i - 1]];
                }

                // Không chọn vật i
                int notPick = dp[i - 1][j];

                dp[i][j] = max(pick, notPick); // Chọn giá trị lớn nhất giữa vật lấy và không lấy
            }
        }
    }
    return dp[n][X]; // Trả lại giá trị cuối cùng của bảng
}

int main(){
    int n, X;
    cin >> n >> X;
    vector<int> w(n);
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }

    cout << maxSumValues(w, v, X, n);
    return 0;
}
