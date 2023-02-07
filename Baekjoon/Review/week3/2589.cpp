// 상하좌우로 이웃한 육지로만 이동 가능함 & 같은 곳 두 번 이상 지나지 않음
// 보물은 서로 간에 "최단 거리"로 이동하는데 있어 "가장 긴 시간"이 걸리는 육지 두 곳에 나뉘에 묻혀있디
#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
char _map[53][53];
int n, m, ret, visited[53][53];
vector<pair<int, int>> lands;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> _map[i][j];
            if(_map[i][j] == 'L') lands.push_back({i, j}); // 육지들을 벡터에 담는 것이 옳을까? 큐나 스택이 아니라?
        }
    }
    for(pair<int, int> land : lands){
        // 시작점 설정 & 초기화
        int sy = land.first;
        int sx = land.second;
        memset(visited, 0, sizeof(visited));

        // bfs 진행
        queue<pair<int, int>> q;
        visited[sy][sx] = 1;
        q.push({sy, sx});
        while(q.size()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){ // 4방향 탐색
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(visited[ny][nx] || _map[ny][nx] == 'W') continue; // 이미 방문했거나 바다이면 건너뜀
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
                ret = max(ret, visited[ny][nx]);
            }
        }
    }
    cout << ret - 1 << "\n";
}