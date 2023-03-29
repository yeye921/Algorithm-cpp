// 모든 노드에 대해 DFS돌려서 dfs의 횟수를 구하면 됨
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, visited[1004], a, b, cnt;
vector<int> adj[1004];
void dfs(int node){
    visited[node] = 1;
    for(int next : adj[node]){
        if(!visited[next]) dfs(next);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}