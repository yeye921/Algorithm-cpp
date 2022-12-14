// connected component 문제 -> dfs로 풀기

// 1. 기존 그림에서 앞뒤를 뒤집은 모양으로 푼다고 가정 => 직사각형 넓이에 지장 없음
// 2. (x, y)좌표를 (y, x)좌표로 입력받음

// 모르겠는 것
// 1) 왼쪽 아래 꼭지점 좌표와 오른쪽 위 꼭지점 좌표가 주어졌을 때 그 영역에 속한 좌표들을 1로 채우는 방법
#include <bits/stdc++.h>
using namespace std;
#define y1 aaa
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, -1, 0};
int n, m, k, y1, x1, y2, x2;
int a[104][104], visited[104][104];
vector<int> ret;
int dfs(int y, int x){
    visited[y][x] = 1;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if(visited[ny][nx] || a[ny][nx] == 1) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}
int main(){
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        // (x, y)가 주어지는게 아니라 x, y좌표가 주어지는 것임 !! (이걸 깨닫는게 중요)
        cin >> x1 >> y1 >> x2 >> y2; // 따라서 각각 x, y로 입력 받음 

        // 1. 항상 행 기준으로 탐색!
        for(int i = y1; i < y2; i++){
            for(int j = x1; j < x2; j++){
                a[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != 1 && visited[i][j] == 0){
                ret.push_back(dfs(i, j));
            }
        }
    }

}