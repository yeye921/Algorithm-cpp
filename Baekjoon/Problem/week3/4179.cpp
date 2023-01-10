// 이전풀이(내 풀이): 완전탐색 => 시간초과남
// 큰돌 풀이: 불의 최단거리 배열을 만들고 지훈이의 최단거리 배열을 만듬(각 좌표에서 불보다 빠르면 이어서 탐색 진행)
// => 불과 지훈이의 최단거리를 비교해가면서 탐색 진행
 
// 포인트 !
// 1. 지훈이의 위치는 하나지만 불의 위치는 여러개 나올 수 있음 (항상 문제 잘 확인!)
// 2. 이 문제는 "불이 아무것도 없을 때"라는 반례가 존재한다!! => 이거 예외처리 안하면 틀림 (중요!)
// (처음에 fire_check를 INF값으로 하고 나중에 조건문에서 INF인지 확인하면 됨)
// 3. 1 1 J 처럼 J가 가장자리에 있는 경우도 존재 !
#include <bits/stdc++.h>
using namespace std;
#define map aaa
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int INF = 987654321;
int r, c, y, x, ret;
int fire_check[1004][1004], jihun_check[1004][1004]; // 각각의 최단거리 배열(=visited)
char map[1004][1004];
pair<int, int> jihun;
int main(){
    fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);
    queue<pair<int, int>> q;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];
            if(map[i][j] == 'J'){
                jihun_check[i][j] = 1;
                jihun = {i, j};

            }
            if(map[i][j] == 'F'){
                fire_check[i][j] = 1; // 불의 위치 여러개 나올 수 있음
                q.push({i, j});
            }
        }
    }
    // 불의 최단거리 배열 구하기
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(fire_check[ny][nx] != INF || map[ny][nx] == '#') continue; // 이미 방문했거나(INF가 아님) 벽이면 건너뜀
            fire_check[ny][nx] = fire_check[y][x] + 1; // 최단거리 배열!
            q.push({ny, nx});
        }
    }
    // 지훈이의 최단거리 배열 구하기
    q.push(jihun);
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        if(y == 0 || x == 0 || y == r - 1 || x == c - 1){ // 미로의 가장 자리가 접한 공간이면 탈출 (가장자리를 체크하는 법 !)
            ret = jihun_check[y][x]; // ret으로 최단거리 할당
            break;
        }
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(jihun_check[ny][nx] || map[ny][nx] == '#') continue; // 이미 방문했거나 벽이면 건너뜀
            if(fire_check[ny][nx] <= jihun_check[y][x] + 1) continue; // 이 부분이 중요! (지훈이가 불보다 빠른지/이미 불이 퍼졌는지 체크)
            jihun_check[ny][nx] = jihun_check[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if(ret != 0) cout << ret << "\n"; // ret = 0인 경우 (= 불이 모두 퍼져 더이상 이동할 수 없는 경우)
    else cout << "IMPOSSIBLE\n";
    return 0;
}
