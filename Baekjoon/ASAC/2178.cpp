// 목표: 시작위치와 도착위치가 주어졌을 때 최단 거리 구하기
// m1) bfs로 최단거리 배열 만들고 해당 좌표 출력
// m2) dfs로 ...? 근데 최소값이니까 갱신해야함
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, y, x, a[104][104], ret, visited[104][104];
string s;
void bfs(int y, int x){
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(!visited[ny][nx] && a[y][x]){ // 1인지 확인
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            a[i][j] = s[j] - '0';
        }
    }
    bfs(0, 0); // =(1,1)
    cout << visited[n - 1][m - 1] << "\n"; 
}