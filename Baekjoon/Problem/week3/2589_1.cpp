// 15686 문제와 유사

// 2차원 벡터 탐색하는 법 알아두기 !!
// bfs 알고리즘 복습 필요
// combi 함수 암기 필요

// 내 풀이로 풀면 시간초과 남 => 2개 뽑는 것을 재귀함수로 구현해서 인듯

// 1. 육지 중에 2곳 뽑음
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
int ret = 987654321;
void combi(int start, vector<int> v){
    if(v.size() == 2){ // 2개 다 뽑으면
        pickedList.push_back(v);
        return;
    }
    for(int i = start + 1; i < landList.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}
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
    combi(-1, v); // 1. 육지 중에 2곳 뽑음

    // 2. 그 두 곳 사이의 최단 거리 구함
    // 3. 최단거리 중 가장 큰 값을 출력
    int ret = 1; // 최대값은 최소값 부터 !!
    for(vector<int> v : pickedList){ // 완전탐색 (경우의 수 탐색)
        // 경우의 수 마다 초기화하는 것 중요 !!
        memset(visited, 0, sizeof(visited));

        // 두 곳중 한 곳에서 탐색 시작, 다른 점을 도착 점으로 설정
        // 두 곳의 좌표 뽑아내기
        pair<int, int> a = landList[v[0]];
        pair<int, int> b = landList[v[1]];

        // a점부터 탐색시작 
        bfs(a.first, a.second);
        ret = max(ret, visited[b.first][b.second]); // 두 점의 최단 거리 중 최대가 되는 거리 업데이트
    }
    cout << ret - 1 << "\n";
    return 0;
}