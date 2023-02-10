// 큰돌 풀이 (400ms)

// Q. visited = 1 처리가 dfs의 맨 앞에 있으면 안되나..?
#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int r, c, ret;
bool visited[30]; // 알파뱃 개수 = 26개
char _map[23][23];
void dfs(int y, int x, int cnt){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        int next = (int)(_map[ny][nx] - 'A');
        if(visited[next]) continue;
        visited[next] = 1;
        dfs(ny, nx, cnt + 1);
        visited[next] = 0;
    }
    ret = max(ret, cnt);
}
int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> _map[i][j];
        }
    }
    visited[(int)_map[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << ret << "\n";
    return 0;
}