// 당근마킷 문제
// 한 칸 움직일 때마다 당근 하나씩 소모됨. 최단거리로 갈 때 당근마킷까지 가는데 소모되는 당근의 개수는?
// 승원이는 육지(1)로만 갈 수 있으며 바다(0)로는 못감. 상하좌우로만 움직일 수 있음
// 입력: 맵의 세로길이(n), 가로길이(m), 현재위치(y, x), 당근마킷 위치(y, x)

// 2차원 좌표니까 인접리스트보다는 인접행렬이 나을듯
#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, m, y, x, ey, ex, qy, qx;
int a[max_n][max_n], visited[max_n][max_n];

void bfs(int y, int x){ // 여기서 큐 써먹어야 함. bfs는 한번만 호출됨
    queue<pair<int, int>> q;
    visited[y][x] = 1; // 방문처리 함
    q.push({y, x});

    while(q.size()){
        tie(qy, qx) = q.front(); 
        cout << visited[qy][qx] << " : " << qy << ", " << qx << "\n";
        q.pop();

        // 4방향 탐색
        for(int i = 0; i < 4; i++){
            int ny = qy + dy[i];
            int nx = qx + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(a[ny][nx] == 0 || visited[ny][nx]) continue;  // 바다이거나 이미 방문한 곳이면
            visited[ny][nx] = visited[qy][qx] + 1; // 최단거리 배열 처리
            q.push({ny, nx});
        }
    }
}
int main(){
    cin >> n >> m;
    cin >> y >> x;
    cin >> ey >> ex; // 당근마킷 위치
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    // bfs돌리고 최단거리 배열 출력
    bfs(y, x);
    cout << visited[ey][ex] << "\n"; // 승원위치부터 당근마킷까지의 최단거리 출력

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}