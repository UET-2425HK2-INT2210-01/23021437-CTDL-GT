#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001]; // danh sách kề
bool visited[1001];    // đánh dấu đã thăm

// DFS đệ quy
void dfs(int u) 
{
    visited[u] = true;
    for (int v : adj[u]) 
    {
        if (!visited[v]) 
        {
            dfs(v);
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;

    // Đọc cạnh
    for (int i = 0; i < m; ++i) 
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // vì đồ thị vô hướng
    }

    int count = 0;

    // Duyệt tất cả các đỉnh
    for (int i = 1; i <= n; ++i) 
    {
        if (!visited[i]) 
        {
            dfs(i);
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}
