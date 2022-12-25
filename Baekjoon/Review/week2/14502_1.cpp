// 2차원 배열 복사하는 법: memcpy(a, temp, sizeof(a));
// 2차원 배열 초기화하는 법: 1) fill(&a[0][0], &a[0][0] + n * m, 1) 
//                     2) memset(a, 0또는-1, sizeof(a))

// 1. 3개 벽 세우기
// 2. 바이러스 퍼짐 처리
// 3. 안전영역 크기 세기
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m;
int a[10][10];
bool visited[10][10];
vector<pair<int, int>> v;
void dfs(int x, int y){ // x를 행으로 생각
    visited[x][y] = 1; 
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        // dfs를 어떤 경우에 진행해야함 ..? => a[nx][ny] == 0 && visited[x][y] == 0
        // 여기서 체크하는 조건이 다음과 같이 다양하게 나올 수 있음
        // if(a[nx][ny] == 1 || visited[nx][ny]) continue;
        // if(a[nx][ny] == 1 || a[nx][ny] == 2 || visited[nx][ny]) continue;
        if(a[nx][ny] == 0 && !visited[nx][ny]){
            cout << nx << ny << " " << a[nx][ny] << "\n";
            dfs(nx, ny);
        } 
        // dfs(nx, ny);
    }
}
int solve(){
    // 초기화하는거 매우 중요 !!!
    memset(visited, 0, sizeof(visited));
    int ans = 0;
    // 바이러스 퍼짐 처리
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 2) dfs(i, j);        
        }
    }
    // 안전영역 크기 세기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!a[i][j] && !visited[i][j]) ans++;
        }
    }
    return ans;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(!a[i][j]) v.push_back({i, j}); // 벽을 세울 수 있는 좌표들을 v에 담음
        }
    }
    // v에서 3개 좌표 뽑아서 벽 세움
    // 3개 뽑는 법 => 3중 for문 이용
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                // i, j, k 는 v의 인덱스를 뜻함 
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
                // 2,3 과정 진행됨
                ans = max(ans, solve());
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0; // 완전 탐색은 해제가 중요 
            }
        }
    }
    cout << ans << "\n";
    return 0;
}