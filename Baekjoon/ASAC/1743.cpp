// 떨어진 음식물 중에 제일 큰 음식물만을 피해가려고 함
// 제일 큰 음식물 = 제일 큰 연결된 컴포넌트

// 실수포인트: 자꾸 dfs결과가 4가 나와야 하는데 1이 나옴 
// 원인=> if(visited[ny][nx] && _map[ny][nx] == 0) continue; // ||로 해야되는데 &&으로 연결했음!
// 원인=> if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue; // 범위 체크를 n,m으로 해야되는데 r,c로 했음!
#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int n, m, k, r, c, _map[104][104], ret;
bool visited[104][104];
int dfs(int y, int x){
    int ret = 1;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx] || _map[ny][nx] == 0) continue; // 이미 방문했거나 음식물이면 건너뜀
        ret += dfs(ny, nx);
    }
    return ret;
}
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        cin >> r >> c;
        _map[r - 1][c - 1] = 1;
    }

    // 음식물만 dfs탐색하며 가장 큰 connected component의 크기를 구해야 함
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && _map[i][j]){ // 방문하지 않았고 음식물이면 dfs탐색 진행
                ret = max(ret, dfs(i, j)); // 최대값 갱신
            }
        }
    }
    cout << ret << "\n";
    return 0;
}