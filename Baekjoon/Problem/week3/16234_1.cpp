// 힌트 얻고나서 두번째 시도
// 내 풀이
// 2차원 좌표의 모든 정점에서 dfs하면서 해당 영역 바꿈

// 2차원 배열 복사하는 법: memcpy(복사받을 메모리, 복사할 메모리, 복사할 값의 길이)
// 반례까지 답은 다 맞게 나오는데 틀림 => 맞왜틀 => visited배열로 인구이동시키면 안됨
// => 그러면 다음 정점에서 dfs탐색할때 이전 visited배열 초기화되서 방문했던곳 다시 방문할 수 있음!
// 배열을 직접적으로 수정하면 다른 케이스에서 수정된 배열로 적용됨 => 배열 직접 수정하지 말 것 !!!
#include <bits/stdc++.h>
using namespace std;
#define map aaa
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, l, r, map[53][53], visited[53][53], temp[53][53], sum, cnt;
vector<pair<int, int>> v;
// 해당 좌표에서 시작해서 connected component의 넓이, 개수 셈
void dfs(int y, int x, vector<pair<int, int>> &v){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        int dist = abs(map[y][x] - map[ny][nx]);
        if(dist >= l && dist <= r){
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            sum += map[ny][nx];
            dfs(ny, nx, v);
        }
    }
}
int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    while(1){ // 테스트케이스 => 초기화 중요 !!
        memset(visited, 0, sizeof(visited));
        bool flag = 0; // 인구이동 발생 여부 체크

        // 2차원 배열의 모든 정점에 대해 dfs수행
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i, j});
                    sum = map[i][j];
                    dfs(i, j, v);
                    if(v.size() == 1) continue; // 인접한 정점으로의 이동이 일어나지 않으면 건너뜀

                    // 한 dfs가 끝나면 v를 토대로 인구이동 시킴
                    for(pair<int, int> b : v){
                        map[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if(flag == 0) break; // 인구 이동이 일어나지 않았으면 종료
        cnt++;  
    }
    cout << cnt << "\n";
}
// 반례
// 4 1 9 96 93 74 30 60 90 65 96 5 27 17 98 10 41 46 20