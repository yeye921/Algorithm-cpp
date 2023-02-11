// 큰돌 풀이
// 핵심 알고리즘 !! 
// 방문했던 문자들을 vector에 담는 것이 아니라 visited배열에 A~Z를 0~26으로 평행이동시켜 저장
#include <bits/stdc++.h>
using namespace std;
int R, C, ret, visited[30];
char a[21][21];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = { 0, 1, 0, -1}; 
void go(int y, int x, int cnt){
    ret = max(ret, cnt); // cnt를 증가시키면서 갱신함
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int next = (int)(a[ny][nx] - 'A'); // 내가 지금 가야할 알파벳 (ex. B일 경우 next = 1)
        
        if(visited[next] == 0){
            visited[next] = 1;  // 방문처리 (완탐 진행)
            go(ny, nx, cnt + 1);
            visited[next] = 0;  // 원복처리 (완탐 해제)
        }
    }
    return;
}
int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }
    visited[(int)a[0][0] - 'A'] = 1; // ! A~Z를 0~26으로 좌표이동시킴 (아스키코드를 이용하여 문자를 숫자로 바꿈)
    go(0, 0, 1);
    cout << ret << '\n';
    return 0;
}