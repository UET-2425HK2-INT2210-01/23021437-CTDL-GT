#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Giá trị đại diện cho "vô cực"
const int INF = 1e9;

// Cấu trúc lưu cạnh có hướng từ u đến v với độ bẩn d
struct Edge {
    int u, v, d;
};

int main() {
    ifstream fin("dirty.txt");     // Mở input
    ofstream fout("dirty.out");    // Mở output

    int n, m, s, e;
    fin >> n >> m >> s >> e;       // Đọc số đỉnh, số cạnh, điểm bắt đầu, điểm kết thúc

    vector<Edge> edges;            // Danh sách cạnh
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); // Ma trận độ bẩn

    // Đặt độ bẩn từ một đỉnh đến chính nó bằng 0
    for (int i = 1; i <= n; ++i) graph[i][i] = 0;

    // Đọc thông tin các cạnh
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;
        edges.push_back({u, v, d}); // Lưu vào danh sách cạnh

        // Cập nhật độ bẩn nhỏ nhất nếu có nhiều cạnh trùng u → v
        if (d < graph[u][v]) {
            graph[u][v] = d;
        }
    }

    //Bellman-Ford từ s đến e

    vector<int> dist(n + 1, INF);    // dist[v] là độ bẩn nhỏ nhất từ s đến v
    vector<int> parent(n + 1, -1);   // Lưu cha để truy vết đường đi
    dist[s] = 0;                     // Khởi tạo điểm bắt đầu

    // Lặp n - 1 lần để cập nhật độ bẩn ngắn nhất
    for (int i = 1; i <= n - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] < INF && dist[edge.u] + edge.d < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.d;
                parent[edge.v] = edge.u;
            }
        }
    }

    // Ghi độ bẩn nhỏ nhất từ s đến e
    fout << dist[e] << '\n';

    // Truy vết đường đi từ e quay ngược lại đến s
    vector<int> path;
    for (int v = e; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end()); // Đảo ngược lại theo thứ tự s → e

    // Ghi đường đi ra file
    for (int city : path) {
        fout << city << " ";
    }
    fout << '\n';

    // Floyd-Warshall cho mọi cặp đỉnh

    vector<vector<int>> d = graph; // Sao chép ma trận gốc

    // Ba vòng lặp Floyd-Warshall
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // Ghi ma trận kết quả ra file (d[i][j] là độ bẩn ít nhất từ i → j)
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (d[i][j] == INF)
                fout << "INF ";
            else
                fout << d[i][j] << " ";
        }
        fout << '\n';
    }

    return 0;
}
