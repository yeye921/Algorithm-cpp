// 방귀는 상하좌우 네 방향으로 뻗어나가며 종화와 연결된 "육지"는 모두 다 오염된다
// "바다"로는 방구가 갈 수 없다
// 맵이 주어졌을 때, 종화가 몇번만에 모든 육지를 오염시킬 수 있는지 말해보자
// (n: 세로길이 = x, m: 가로길이 = y)
#include <iostream>
using namespace std;
int n, m, cnt;
int a[104][104];
bool visited[104][104];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1; // !! 방문 처리
    cout << y << ", " << x << "\n";

    // 4방향 탐색
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx] || a[ny][nx] == 0) continue;
        dfs(ny, nx);
    }
    // cout << y << ", " << x << "종료됨\n";
    return;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    // 그래프 탐색
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1 && !visited[i][j]){ // 방문하지 않았고 육지이면
                cnt ++;
                cout << cnt << " : " << i << ", " << j << "\n";
                dfs(i, j);
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}