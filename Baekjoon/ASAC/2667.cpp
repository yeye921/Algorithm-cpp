// 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 함
// connected component의 개수, 각 연결된 컴포넌트의 크기를 구해야함
#include <bits/stdc++.h>
using namespace std;
string s;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int n, _map[30][30], visited[30][30], num;
vector<int> v;
int dfs(int y, int x){
    int ret = 1;
    visited[y][x] = num; // 각 단지(=connected component)에 번호를 붙임
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(visited[ny][nx] || _map[ny][nx] == 0) continue; // 이미 방문했거나 0이면 건너뜀
        ret += dfs(ny, nx);
    }
    return ret;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n ; j++){
            _map[i][j] = s[j] - '0';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && _map[i][j]){ // 이전에 방문하지 않았고 1이면 dfs돌림
                num++;
                int cnt = dfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    // 오름차순 정렬 후, 출력
    sort(v.begin(), v.end());
    cout << num << "\n";
    for(int i : v) cout << i << "\n";
    return 0;
}