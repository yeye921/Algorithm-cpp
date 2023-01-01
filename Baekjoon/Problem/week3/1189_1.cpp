// 큰돌 풀이

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
    if(y == 0 && x == m - 1){
        if(k == visited[y][x]) return 1;
        return 0;
    }

    // k번만에 방문한게 몇개 있느냐
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 'T') continue;
        visited[ny][nx] = visited[y][x] + 1; // 최단거리 + 1 (bfs추가 사용) => 경우의 수
        ret += go(ny, nx); // 탐색시작
        visited[ny][nx] = 0; // 완전탐색 해제
    }
    return ret;
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