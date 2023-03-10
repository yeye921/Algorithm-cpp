// 이 문제 자꾸 실수하는 것: 문제에서 열개수 > 행개수 순으로 주어지는대 자꾸 반대로 받음 !!
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, -1, 0, 1}, dx[] = {-1, 0, 1, 0};
int r, c, num, cnt, area, mx;
int a[53][53], visited[53][53], compSize[53];
int dfs(int y, int x, int cnt){
    int ret = 1;
    if(visited[y][x]) return 0;
    visited[y][x] = cnt;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if(a[y][x] & (1 << i)) continue; // 이동하려는 방향에 벽이 있으면 이동 못함
            ret += dfs(ny, nx, cnt);
    }
    return ret;
}
int main(){
    cin >> c >> r; // 이 순서 주의해야함!! (열개수 > 행개수 순임)
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> num;
            a[i][j] = num;
        }
    }
    
    // 1.방의 개수 2.가장 넓은 방의 넓이 
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!visited[i][j]){
                cnt++; // 용도: 방의 개수세기, 영역 색칠 하기
                compSize[cnt] = dfs(i, j, cnt); // 영역 id - 해당 영역의 넓이 매핑
                area = max(area, compSize[cnt]); // 가장 넓은 방의 넓이
            }
        }
    }
    // 3.하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 넓이
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(i + 1 < r){
                int a = visited[i + 1][j];
                int b = visited[i][j];
                if(a != b){
                    mx = max(mx, compSize[a] + compSize[b]);
                }
            }
            if(j + 1 < c){
                int a = visited[i][j + 1];
                int b = visited[i][j];
                if(a != b){
                    mx = max(mx, compSize[a] + compSize[b]);
                }
            }
        }
    }
    cout << cnt << "\n";
    cout << area << "\n";
    cout << mx << "\n";
    return 0;
}    