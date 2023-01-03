// 완전탐색 문제 => 계속 실험하고 초기화하는 것을 반복함

// 한수는 현재 왼쪽 아래점에 있고 집은 오른쪽 위에 있다. 
// 그리고 한수는 집에 돌아가는 방법이 다양하다.

// 목표: (0, 0)에서 (0, c-1)까지 가는데 거리가 k인 가짓수 구하기

// 이전 풀이와의 차이
// 최단거리 배열을 이용하지 않고 dist + 1을 이용함
// void형 dfs를 이용함

// dfs를 재귀함수로 구현한다면 다음 3가지만 잘 체크하면 됨
// 1. 재귀함수 기저사례
//    목적지에 도착하면 탐색할 필요가 없으므로 도착지를 기저사례로 삼는다
// 2. 백트래킹
//    원하고자 하는 거리는 k이므로 k를 넘어서는 거리의 이동경로를 알 필요가 없다
// 3. 모든 경로 탐색
//    모든 경로를 탐색해야하므로 dfs로 하나의 이동경로가 만들어졌다면, 
//    그 이동경로에서 방문을 한 점을 방문하지 않은 점으로 바꿔준다. 그래야 모든 경로 탐색이 가능하다
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int m, n, k, cnt, a[5][5], visited[5][5];
void dfs(int y, int x, int dist){
    if(dist > k) return;
    if(x == n - 1 && y == 0 && dist == k){ // 도착 && 도착지점까지의 거리가 k이면
        cout << "가짓수 추가\n";
        cnt++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if(visited[ny][nx] || a[ny][nx]) continue;
        visited[ny][nx] = 1;
        cout << ny << nx << ": " << dist + 1 << "\n";
        dfs(ny, nx, dist + 1);
        visited[ny][nx] = 0; // 완전탐색 해제
    }
}
int main(){
    cin >> m >> n >> k;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == 'T') a[i][j] = 1;
        }
    }
    visited[m - 1][0] = 1;
    dfs(m - 1, 0, 1);
    cout << cnt;
}