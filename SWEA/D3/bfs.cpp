// BFS(너비우선탐색)는 그래프를 탐색하는 알고리즘
// 어떤 정점에서 시작해 다음 깊이의 정점으로 이동하기 전에 현재 깊이의 모든 정점을 탐색하며, 방문한 정점은 다시 방문하지 않는 알고리즘이다.
// 같은 가중치를 가진 그래프에서 최단거리 알고리즘으로 쓰인다.
// (한번 방문한 노드는 다시한번 방문하지 않는다)

// "최단거리"로 당근마켓으로 향한다고 할 때, 당근 몇개를 소모해야 당근마켓에 갈 수 있는지를 구해라
// 승원이는 육지(1)로만 갈 수 있다. 한 칸 움직일 때 당근한개가 소모된다.
// 결론: (sy, sx)에서 (ey, ex)로 가는 최단거리를 구하기. 즉, 최단거리 배열을 만들고 그 배열의 (ey, ex)값 출력하면 끝!
#include <iostream>
#include <queue>
using namespace std;
int n, m;
int sy, sx, ey, ex;
int arr[104][104];
bool visited[104][104];
int ret;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int main(){
    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ey >> ex;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> q; // 레벨별 탐색을 위해 큐 생성
    visited[sy][sx] = 1;     // 최단거리 배열 초기값
    q.push({sy, sx});        // 시작점 삽입
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){ // 인접한 정점(같은 깊이의 정점)을 큐에 넣음
            int ny = y + dy[i]; 
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] || !arr[ny][nx]) continue; // 바다이거나 방문한 곳이면 건너뜀
            visited[ny][nx] = visited[y][x] + 1; // 중요! 최단거리 배열 설정
            q.push({ny, nx});
        }
    }
    cout << visited[ey][ex] << "\n"; // 최단거리 배열에서 목표지점의 값(=시작점에서 목표지점까지의 최단거리) 출력
}