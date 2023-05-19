// DFS: 그래프를 탐색할 때 쓰이는 알고리즘.
// 특정한 노드 s에서 시작해 s로부터 도달할 수 있는 모든 정점들을 재귀적으로 방문하는 알고리즘
// s로부터 가장 멀리있고 깊이있는 노드부터 탐색하게 되는 알고리즘
// 한번 방문한 노드는 다시 방문하지 않는다
#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
int arr[max_n][max_n];
int visited[max_n][max_n];
int n, m;
int ret;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(arr[ny][nx] && !visited[ny][nx]) dfs(ny, nx);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    // 육지(1)로만 갈 수 있다. 방귀는 네방향으로 뻗어가며 연결된 육지는 모두 다 오욤된다
    // 방구를 최소 몇번 외쳐야 모든 육지를 오염시킬 수 있는지 구하기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] && !visited[i][j]){ // 육지이면서 방문하지 않은 곳이어야 탐색가능
                ret++;
                dfs(i, j);
            }
        }
    }
    cout << ret << "\n";

}