// 3*3 맵 입력받음. {0, 0}부터 4방향을 기준으로 한칸씩 탐색해나가며 방문한 정점은 다시 방문하지 ㅇ낳는다
// 0은 갈 수 없는 지역. 1은 갈 수 있는 지역
#include <bits/stdc++.h>
using namespace std;
const int n = 3;
bool a[n][n], visited[n][n];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, -1, 0};
void go(int y, int x){
    visited[y][x] = 1;
    cout << y << " , " << x << "\n";
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(a[ny][nx] == 0 || visited[ny][nx]) continue;
        go(ny, nx);
    }

}
int main(){
    // 맵 입력 받음
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    go(0, 0);
}