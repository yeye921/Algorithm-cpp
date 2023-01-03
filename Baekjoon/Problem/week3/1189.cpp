// 큰돌 풀이
// 완전 탐색은 그래프로 만들어서 생각하면 쉬움
// 레벨 별로 탐색하는게 아니기때문에 bfs가 아니라 dfs로 풀어야 함
// 재귀적으로 탐색하는 문제
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, visited[10][10];
char a[10][10];
string s;
int go(int y, int x){
    if(y == 0 && x == m - 1){ // 도착지점에 도달하면 종료
        if(k == visited[y][x]) return 1; // 집까지 도착하는 거리가 k이면 1반환 (즉, cnt++)
        return 0; // 아니면 0반환
    }
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 'T') continue;
        visited[ny][nx] = visited[y][x] + 1; // 최단거리(dist)를 기록할 배열 필요함 (bfs 사용) => 경우의 수
        ret += go(ny, nx); // ret에는 1또는 0이 쌓이게 됨
        visited[ny][nx] = 0; // 완전탐색 해제 (테스트케이스 초기화)
    }
    return ret; // ret: 거리가 k인 가짓수
}
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j];
        }
    }
    visited[n - 1][0] = 1; // 현수의 위치
    cout << go(n - 1, 0) << "\n";
}