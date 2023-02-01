// 경우의 수 문제 > 경우의 수는 더하기이다
// 완전탐색 & 백트래킹 문제
// 한수가 집에 돌아가는 방법은 다양하다
// 단, 한수는 똑똑하여 한번 지나친 곳을 다시 방문하지 않는다

// 내가 푼 풀이 > 맞았음
// Q. 완전 탐색 시간복잡도를 어떻게 계산하지? 5*5가 최대

// 맞왜틀 팁: 전역변수를 사용할 때 주의할 점 (ny, nx를 전역변수로 선언하면 틀림)
// 지역변수(함수내변수)는 스택에 쌓임 > 어떠한 함수와도 독립적임
// 전역변수는 BSS/Data segment에 쌓임 > 다른 함수에도 다 영향을 미침
// 매개변수로 넘기는 것은 지역변수로 하자 !!

// 이 문제는 BFS의 개념이 섞여 있음 > 최단거리를 모아놓는 배열이 필요함
// => 최단거리가 k인 것이 몇개 있는지 알기 위해
#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int r, c, k, sy, sx, ey, ex, cnt;
bool visited[8][8];
char _map[8][8];
// 레벨 별로 탐색하는게 아니라 한 경로마다 탐색하는 것?이므로 dfs탐색 진행해야함
void dfs(int y, int x, int dist){
    visited[y][x] = 1;
    // cout << y << " " << x << " :" << cnt << "\n"; 
    cout << y << " " << x << " " << dist << "\n";
    if(dist > k) return; // 기저사례
    if((dist == k) && (y == ey) && (x == ex)){ // 거리가 k이고 집에 도착했으면 가짓수 증가 후 종료
        cnt++;
        return;
    }
    for(int i = 0; i < 4; i++){ // 현재위치에서 4방향으로만 이동가능
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue; // 범위를 초과하거나 이미 방문한 곳은 건너뜀
        if(_map[ny][nx] == 'T') continue; // 가지 못하는 부분은 건너뜀
        visited[ny][nx] = 1;
        dfs(ny, nx, dist + 1);
        visited[ny][nx] = 0;
    }
}
int main(){
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> _map[i][j];
        }
    }

    // 시작지점 설정
    sy = r - 1, sx = 0;
    ey = 0, ex = c - 1;
    int dist = 1;
    dfs(sy, sx, dist);
    cout << cnt << "\n";
    return 0;
}