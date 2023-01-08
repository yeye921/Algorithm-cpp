// 15686 문제와 유사

// 2차원 벡터 탐색하는 법 알아두기 !!
// bfs 알고리즘 복습 필요
// combi 함수 암기 필요

// 내 풀이로 풀면 시간초과 남 => 2개 뽑는 것을 재귀함수로 구현해서 인듯

// 1. 육지 중에 2곳 뽑음 => m1) 이중for문 이용, m2) 재귀함수 이용 
// 2. 그 두 곳 사이의 최단 거리 구함
// 3. 최단거리 중 가장 큰 값을 출력
#include <bits/stdc++.h>
using namespace std;
#define map aaa
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<vector<int>> pickedList; // 육지 뽑는 경우의 수를 2차원 배열로 저장
vector<pair<int, int>> landList;
char map[54][54];
int n, m, visited[54][54];
void bfs(int y, int x){ // bfs는 한번만 호출됨
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] || map[ny][nx] == 'W') continue; // 이미 방문했거나 바다이면 건너뜀
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}
int main(){
    vector<int> v;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'L') landList.push_back({i, j});
        }
    }
    // combi(-1, v); // 1. 육지 중에 2곳 뽑음
    // 이중 for문 이용해서 육지 중 2곳 뽑음
    int ret = 1;
    for(int i = 0; i < landList.size(); i++){
        for(int j = 0; j < i; j++){
            // 경우의 수 마다 초기화하는 것 중요 !!
            memset(visited, 0, sizeof(visited));
            
            // 뽑은 2개 가지고 할일            
            pair<int, int> a = landList[i];
            pair<int, int> b = landList[j];
            bfs(a.first, a.second);
            ret = max(ret, visited[b.first][b.second]); // 두 점의 최단 거리 중 최대가 되는 거리 업데이트
        }
    }
    cout << ret - 1 << "\n";
    return 0;
}