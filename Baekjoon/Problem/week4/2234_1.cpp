// 내 풀이
// 굵은 선은 벽을 나타내고, 점선은 벽이 없어서 지나다닐 수 있는 통로를 나타낸다

// 구해야 할 것
// 1. 이 성에 있는 방의 개수
// 2. 가장 넓은 방의 넓이
// => 위 2가지는 dfs로 해결 가능함

// 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
// => 얘는 완전탐색? 벽을 벡터에 담아놓고 해당 좌표부터 dfs 돌림
// 일단 2번까지만 목표로 하기로 함

// 실수tip: n, m으로 받으면 행/열이 헷갈림 
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, -1, 0, 1}, dx[] = {-1, 0, 1, 0};
int n, m, num, cnt, area, ret;
int _map[53][53], visited[53][53];
vector<pair<int, int>> wall;
int dfs(int y, int x){
    int ans = 1;
    cout << y << " " << x << "\n";
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
        if(_map[y][x] & (1 << i)) continue;  // 벽이 있는 방향으로는 이동 못함
        ans += dfs(ny, nx);
    }
    return ans;
}
int main(){
    cin >> n >> m; // n:열, m:행
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            _map[i][j] = num;
            if(_map[i][j] > 0) wall.push_back({i, j});
        }
    }

    // 1,2번
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                cnt++;
                area = max(area, dfs(i, j)); // 최대가 되는 넓이 갱신
            }
        }
    }
    // 3번 (벽을 없애고 해당 정점부터 dfs돌리고 갱신해나감)
    // y=0, x=0, y=m, x=n인 벽은 제외함
    for(pair<int, int> pi : wall){ // 좌표로 탐색
        int y = pi.first;
        int x = pi.second;
        for(int i = 0; i < 4; i++){ // 4방향으로 체크
            if(_map[y][x] & (1 << i)){
                
            }
        }
        // 벽을 없앤 다음에 dfs돌리고 나서 벽을 다시 세워야 함! (like 완전탐색)
        // if(y == 0 && (_map[y][x] & 2)) _map[y][x] -= 2;
        // if(y == m & (_map[y][x] & 8)) _map[y][x] -= 8;
        // if(x == 0 && (_map[y][x] & 1)) _map[y][x] -= 1;
        // if(x == n & (_map[y][x] & 4)) _map[y][x] -= 4;
        // int temp = _map[y][x];
        // if(_map[y][x] > 0){
        //     // 
        //     _map[y][x]
        // }
    }
    
    cout << cnt << "\n";
    cout << area << "\n";
}