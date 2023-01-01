// 완전탐색 문제
// 한수는 현재 왼쪽 아래점에 있고 집은 오른쪽 위에 있다. 
// 그리고 한수는 집에 돌아가는 방법이 다양하다.

// T로 표시된 부분은 가지 못하는 부분이다 (1)
// 단, 한수는 똑똑하여 한번 지나친 곳을 다시 방문하지는 않는다.

// 한수가 집까지도 도착하는 경우 중 거리가 K인 가짓수를 구하는 것이다.
// => (0, 0)애서 (r, c)까지 가는데 거리가 k인 가짓수를 구하면 됨
// 
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, k, dist,  a[8][8];
bool visited[8][8];
string s;
void dfs(int y, int x){
    dist++;
    cout << y << x << "\n";
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if(a[ny][nx] || visited[ny][nx]) continue; // 방문했거나 가지 못하는 부분인 경우
        if(ny == r - 1 && nx == c - 1) return;
        dfs(ny, nx);
    }
}
int main(){
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++){ // 맵 정보 입력받음
        cin >> s;
        for(int j = 0; j < c; j++){
            if(s[j] == 'T') a[i][j] = 1; 
            else a[i][j] = 0;
        }
    }
    // (0, 0)에서 (r, c)까지 가는 모든 경우의 수 첮가
    // => 어떻게 구함..?
    int cnt = 0;
    while(1){
        // 초기화할 것 체크 => dist, visited
        dist = 0;
        memset(visited, 0, sizeof(visited));
        dfs(0, 0);
        if(dist == 6) cnt++;
        // 탈출조건을 멀로 하지...?
    }
    cout << cnt << "\n";

    // 디버깅
    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j < c; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

}
