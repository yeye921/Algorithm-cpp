// (1, 1)에서 출발하여 (N. M)의 위치로 이동할 때 지나야 하는 최소의 칸 수 구하기 (가중치 같음))
// BFS 문제(가중치가 같은 그래프에서 최단거리 구하기)라는게 바로 떠올라야 함 !

// 모르겠는 것
// 1. cin으로 숫자들 붙어서 입력 받는법 (공백이 없을 경우) => 교안 참고
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int max_n = 104;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int a[max_n][max_n], visited[max_n][max_n];
int n, m, sy, sx, y, x;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    queue<pair<int, int>> q;
    visited[0][0] = 1; // 방문 처리
    q.push({0, 0}); // 처음 위치를 큐에 넣음

    while(q.size()){ // 큐가 빌 때까지 반복 !
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){ // 4방향 탐색
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue; // 오버플로 체크가 항상 맨 위에 와야함!
            if(a[ny][nx] == 0 || visited[ny][nx]) continue; // 이동할 수 없는 칸이거나 방문했던 칸이면
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    cout << visited[n - 1][m - 1] << "\n"; // 정답
    return 0;
}