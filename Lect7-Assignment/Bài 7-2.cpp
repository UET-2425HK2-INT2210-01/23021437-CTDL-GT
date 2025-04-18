#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void findSubMatrix(vector<vector<int>> v, int rows, int cols){
    int r1, c1, r2, c2, maxSum = INT_MIN; // Khởi tạo các biến để lưu kết quả cuối cùng

    for (int top = 0; top < rows; top++){
        // Tạo mảng vector tmp để lưu giá trị tổng các cột (ban đàu bằng 0)
        vector<int> tmp(cols, 0);

        for (int bottom = top; bottom < rows; bottom++){
            for (int col = 0; col < cols; col++){
                // Cộng dồn tổng các cột
                tmp[col] += v[bottom][col];
            }

            // Áp dụng thuật toán Kadane
            int sum = 0;
            int c1_start, c2_end;

            for (int col = 0; col < cols; col++){
                if (sum < 0){
                    sum = tmp[col];
                    c1_start = col;
                    c2_end = col;
                }else{
                    sum += tmp[col];
                    c2_end++;
                }
            }
            if (sum > maxSum){ // Nếu sum > maxSum, cập nhật maxSum và tọa độ sub matrix
                maxSum = sum;
                r1 = top;
                c1 = c1_start;
                r2 = bottom;
                c2 = c2_end;
            }
        }
    }
    // In ra kết quả
    cout << r1 + 1 << " " << c1 + 1 << " " << r2 + 1 << " " << c2 + 1  << " " << maxSum;
    return;
}

int main(){
    string s;
    cin >> s;
    ifstream input (s); // Mở và xuất file

    if(!input){
        cout << "Khong tim thay file.";
        return 0;
    }else{
        int m, n;
        input >> m >> n; // 2 giá trị đầu trong file là số hàng và cột

        vector<vector<int>> matrix(m, vector<int>(n)); // Tạo mảng vector 2 chiều

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                input >> matrix[i][j]; // Đưa các giá trị trong file vào mảng vector 2 chiều
            }
        }
        findSubMatrix(matrix, m, n); // Gọi hàm
    }

    input.close();
    return 0;
}
