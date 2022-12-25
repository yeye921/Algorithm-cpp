// 연결된 컴포넌트(connected component) 수 세는 문제 => 모두 가능 (DFS가 코드 짧음)
// 서로 인접해있는 배추들이 몇 군데에 퍼져있는지 = 총 몇 마리의 지렁이가 필요한지
// 결론: dfs가 몇번 수행되는지 세기 !!

// 맞왜틀이었음 => 테스트케이스 초기화 때문에
// 실수Tip) 테스트케이스 여러 개일 때는 초기화해줘야 할 것 체크 !! (ex. cnt)
// 테스트 케이스마다 맵, visited, cnt .. 등 초기화 시켜줘야 함 !

// 가로길이(m) = x를 의미, 세로길이(n) = y를 의미
#include<bits/stdc++.h>
using namespace std; 
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 
int m, n, k, y, x, ret, ny, nx, t;
int a[51][51];
bool visited[51][51]; 
void dfs(int y, int x){
    visited[y][x] = 1;
    // cout << cnt << " : " << y << ", " << x << "\n"; // for 디버깅
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >=n || nx >= m) continue;
        if(a[ny][nx] == 1 && !visited[ny][nx]){
            dfs(ny, nx);
        }
    }
    return;
}
int main(){ 
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){ // 테스트 케이스가 여러 개일 때는
        // 초기화 시켜줘야 함
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        ret = 0;

        cin >> m >> n >> k;
        // 2차원 좌표 채우기 (y <-> x 순서 바꿈)
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            a[y][x] = 1;
        }
        // 2차원 배열 탐색 (항상 행 기준으로 탐색!)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1 && !visited[i][j]){
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << "\n"; 
    }
    return 0;
}
