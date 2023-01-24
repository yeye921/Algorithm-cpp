// 내 풀이: 답은 맞는데 시간초과나는 풀이 ㅠㅠ

// 내가 느낀 각각의 특징
// dfs: a부터 b까지 가는 모든 경로의 수를 체크함 (나는 되는 루트 하나만 알면되는데 굳이..? 이걸로 해야할까) (각각 경로애 공통으로 적용될 종료 조건이 필요함)
// bfs: 한번에 한 레벨씩 탐색하므로 전체 종료 조건만 주면 됨

// dfs를 어떤 경우에 사용하는 지에대한 공부 필요함 !!!

// bfs보다는 dfs를 쓰는 게 나은 것 같음. dfs 위주의 풀이 !

#include <bits/stdc++.h>
using namespace std;
#define map aaa
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char map[1504][1504];
int r, c, visited[1504][1504], visited_b[1504][1504];
int sy, sx, ey, ex;
bool flag = 0;
vector<pair<int, int>> v; // 백조 두마리의 위치를 담음
vector<pair<int, int>> ice;
void dfs(int y, int x){
    visited_b[y][x] = 1;
    if(y == ey && x == ex){
        flag = 1;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited_b[ny][nx]) continue;
        if(map[ny][nx] == 'X') continue; // 빙하면 건너뜀
        dfs(ny, nx);
    }
    return;
}
int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];
            if(map[i][j] == 'L'){
                v.push_back({i, j});
            }
        }
    }

    int cnt = 0;
    while(1){
        ice.clear();
        cnt++; // 두 백조가 만나기까지 걸리는 날들을 셈
        // 핵심 알고리즘 (치즈 문제와 유사. 다시 풀어보기)
        // 1. 물과 인접한 빙하들 녹임
        // 2. 백조 둘이 만날 수 있는지 체크
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(map[i][j] == '.'){ // 물이면
                    visited[i][j] = 1; // 방문처리함
                    // 4방향 탐색 (빙하이면 물로 변환하는 것은 탐색하면서가 아니라 나중에 한꺼번에 해야함)
                    for(int d = 0; d < 4; d++){
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
                        if(map[ny][nx] == 'X'){ // 빙하이면 
                            ice.push_back({ny, nx}); // 담아놨다가 한번에 물로 변환함
                        }
                    }

                }
            }
        }
        // 담아놨던 얼음들 물로 변환함
        for(pair<int, int> pi : ice){
            map[pi.first][pi.second] = '.';
        }
        // 백조 둘이 만날수 있는지 체크
        sy = v[0].first, sx = v[0].second;
        ey = v[1].first, ex = v[1].second;

        memset(visited_b, 0, sizeof(visited_b));
        dfs(sy, sx);
        if(flag) break; // 백조 둘이 만나면 반복 종료

        // 한차례 끝나면 디버깅
        // cout << cnt << "번째 턴\n";
        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < c; j++){
        //         cout << map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < c; j++){
        //         cout << visited_b[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
    cout << cnt << "\n";
    return 0;
}