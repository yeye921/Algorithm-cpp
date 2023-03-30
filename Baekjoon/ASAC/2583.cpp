// 조금 어려운 문제..
// k개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지,
// 그리고 분리된 각 영역의 넓이가 얼마인지

// 풀이 방법
// 연결된 컴포넌트들은 1로 칠함. 0인 것들에 대해서만 dfs돌림.
// (m, n을 포함하는지 안하는지를 범위 체크할 때 계속 생각해줘야함)

// 좌표랑 칸을 대치하는게 포인트 
// 칸을 어떻게 세지? => 왼쪽 상단 좌표가 그 칸을 대표한다고 생각하면 됨!! (이거 고려해서 범위체크)
// 자꾸 오른쪽 위 정사각형이 안칠해지는 문제 발생 (ey, ex 순서 실수)
#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int n, m, k, sy, sx, ey, ex, _map[104][104], cnt;
bool visited[104][104];
vector<int> v;
int dfs(int y, int x){
    int ret = 1;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];   // m, n을 포함하지 않는게 중요함 ! (왜냐면 끝칸이기 때문에 왼쪽 상단 점이 될수가 없음)
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue; // !! 칸으로 따지면 m*n크기이지만 좌표로 따지면 (m+1)*(n+1)이다 
        if(visited[ny][nx] || _map[ny][nx]) continue; // 이미 방문했거나 1로 칠해져있으면 건너뜀
        ret += dfs(ny, nx);
    }
    return ret;
}
int main(){
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> sx >> sy >> ex >> ey; // 여기 순서 실수함 

        // 칸이랑 좌표를 대치시킴 (여기 직사각형 색칠하는 범위가 중요!)
        for(int y = sy; y < ey; y++){ // ey, ex를 포함하지 않는게 핵심 (= 왼쪽 상단 점이 그 칸을 대표하니까!) 
            for(int x = sx; x < ex; x++){
                _map[y][x] = 1;
            }
        }
    }
    // 디버깅 (by 칸)
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << _map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 0; i < m; i++){ // m,n을 포함안하는 이유: 왼쪽 위 좌표가 그 칸을 대표하니까!
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && _map[i][j] == 0){ // 방문을 안했고 0으로 칠한 것들만 dfs 돌림
                cnt++;
                int area = dfs(i, j);
                v.push_back(area);
            }
        }
    }
    cout << cnt << "\n";
    sort(v.begin(), v.end());
    for(int i : v) cout << i << " ";
    cout << "\n";
}