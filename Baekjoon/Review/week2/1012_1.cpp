#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int t, n, m, k, x, y, cnt;
int a[51][51];
bool visited[51][51]; 
void dfs(int y, int x){
    visited[y][x] = 1;
    // cout << cnt << " : " << y << ", " << x << "\n";  // for 디버깅
    for(int i = 0; i < 4; i++){ // 4방향 탐색
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx] || a[ny][nx] == 0) continue; // 이미 방문했거나 갈 수 없는 지역일 경우
        dfs(ny, nx); // 재귀
    }
    return;
}
int main(){
    cin >> t;
    while(t--){
        cin >> m >> n >> k;   
        cnt = 0;     
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

        // 좌표 입력받음
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            a[y][x] = 1;
        }

        // 항상 행 기준으로 탐색 !!
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] && visited[i][j] == 0){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << "\n";
    }
}