// (1, 1)에서 출발하여 (N. M)의 위치로 이동할 때 지나야 하는 최소의 칸 수 구하기

// 모르겠는 것
// 1. cin으로 숫자들 붙어서 입력 받는법 (공백이 없을 경우)
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int max_n = 104;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int a[max_n][max_n], visited[max_n][max_n];
int n, m, sy, sx, ny, nx, qy, qx;
void bfs(int sy, int sx){ // queue 이용
    queue<pair<int, int>> q;
    visited[sy][sx] = 1; // 방문 처리
    q.push({sy,sx}); // 처음 위치를 큐에 넣음

    while(q.size()){ // 큐가 빌 때까지 반복 !
        tie(qy, qx) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){ // 4방향 탐색
            ny = qy + dy[i];
            nx = qx + dx[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue; // n, m 순서 주의!!! (y = n, x = m)
            if(a[ny][nx] == 0 || visited[ny][nx]) continue; // 이동할 수 없는 칸이거나 방문했던 칸이면
            visited[ny][nx] = visited[qy][qx] + 1;
            q.push({ny, nx});
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    bfs(0, 0);
    cout << visited[n - 1][m - 1] << "\n"; // 정답
    
    // 최단거리 배열 출력
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}