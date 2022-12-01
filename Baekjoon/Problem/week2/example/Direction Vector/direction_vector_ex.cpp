// 3*3 맵을 입력 받음. 맵은 1과 0으로 이루어짐. {0, 0}부터 4가지 방향을 기준으로 한칸씩 탐색해나가며
// 방문한 정점은 다시 방문하지 않으면 방문하는 좌표를 출력하는 코드
// (0은 갈 수 없는 지역, 1은 갈 수 있는 지역)
#include <bits/stdc++.h>
using namespace std;
const int n = 3;
int mp[n][n], visited[n][n];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
void go(int y, int x){
    // 방문한 정점 처리
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){ // 4방향 탐색
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 오버플로우나 언더플로우를 방지하는 코드 (우리가 선언한 배열의 범위를 넘어서면 안됨)
        // 항상 이 코드가 제일 위에 있어야함 (아래 코드에서 ny, nx 참조가 일어나기 때문)
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(visited[ny][nx]) continue; // 방문 체크
        if(mp[ny][nx] == 0) continue; // 갈 수 있는 지역 체크
        cout << ny << " : " << n x << "\n";
        go(ny, nx);
    }
    return;
}
int main(){
    // 2차원 배열 입력 받음
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mp[i][j];
        }
    }
    go(0, 0);
}