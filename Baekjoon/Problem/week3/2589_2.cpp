// 큰돌 풀이 => "모든 육지 지점"에 대해 최단거리 배열 만들어서 가장 최대가 되는 거리 뽑아냄 > 그 중 max값 찾음
// 내 풀이 => 육지 중에 2개를 뽑아서 bfs를 돌려서 그 두 정점의 최단거리 계산해서 배열에 집어넣음 > 그 배열에서 max 값

// 포인트 => 모든 육지 정점에 대한 최단거리 배열 만들기 !!

// 가중치가 같은 그래프에서 최단거리 찾기 => BFS로 풀기 !

// 모든 정점을 기반으로 탐색 시작
// 모든 쌍에 대한 최단 거리를 만들고
// 그 중에서 가장 큰 값을 구하면 끝

// 보물은 서로 간에 최단 거리로 이동하는데 있어 "가장 긴 시간이 걸리는" 육지 두 곳에 나뉘어 묻혀있다
#include<bits/stdc++.h>
using namespace std; 
int n, m, mx, visited[54][54]; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 
char a[54][54];
void bfs(int y, int x){
    memset(visited, 0, sizeof(visited)); // 각 경우에 대해 bfs가 반복적으로 실행되니 테스트케이스처럼 초기화 중요 !
    visited[y][x] = 1; // !! 시작하는 정점을 다시 방문하지 않게 하기 위함 (따라서 최단거리 계산 시, 마지막에 1을 빼줘야 함)
    queue<pair<int, int>> q; 
    q.push({y, x}); 
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
            if(visited[ny][nx]) continue; 
            if(a[ny][nx] == 'W')continue;
            visited[ny][nx] = visited[y][x] + 1; 
            q.push({ny, nx});
            mx = max(mx, visited[ny][nx]); // 정점사이의 거리 중 최대값 갱신
        }
    }
    return;
}
int main(){
    cin >> n >> m; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j]; 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L') bfs(i, j); // 2차원 맵의 모든 정점에서 bfs 탐색 진행
        }
    } 
    cout << mx - 1 << "\n"; // 칸이 아니라 최단시간이기 때문에 -1 해줌
}