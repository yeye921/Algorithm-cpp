#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, k, cnt, visited[10][10];
char a[10][10];
void dfs(int y, int x, int dist){
    if(dist > k) return;
    visited[y][x] = 1;

    if(y == 0 && x == c - 1){
        if(dist == k) cnt++;
        visited[y][x] = 0;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || a[ny][nx] == 'T') continue;
        dfs(ny, nx, dist + 1);
    }
    visited[y][x] = 0;
}
int main(){
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }
    dfs(r - 1, 0, 1);
    cout << cnt << "\n";
}