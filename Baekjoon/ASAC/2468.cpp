// 어떤 지역의 높이 정보가 주어졌을 때, 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 계산하기
// 풀이 방법: 각 높이에 대해 물에 잠기지 않은 점들의 dfs 횟수 구하면 됨
// 완점 탐색 + 백트래킹 문제

// 73%에서 틀림 => 아무 지역도 물에 잠기지 않을 경우를 고려해야함 !!
#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int n, num, sol, _map[104][104], colored[104][104];
bool visited[104][104];
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(visited[ny][nx] || colored[ny][nx]) continue; // 이미 방문했거나 물에 잠겼으면 건너뜀
        dfs(ny, nx);
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            _map[i][j] = num;    
        }
    }

    // 높이의 경우의 수 구하기 
    // m1)그냥 모든 높이(0~100)에 대해 돌려버리기 (높이0은 아무 지역도 물에 안잠기는 경우를 의미!!)
    // 시간복잡도 O(n^3)= 100*100*100 = 100만
    for(int dep = 0; dep <= 100; dep++){ // 테스트케이스 문제는 초기화가 중요!
        fill(&colored[0][0], &colored[0][0] + n*n, 0); 
        memset(visited, 0, sizeof(visited));
        int ret = 0; // 물에 잠기지 않는 영역의 개수 초기화

        int cnt = 0; // 백트래킹 추가
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(_map[i][j] <= dep){
                    colored[i][j] = 1; // 물에 잠겼다는 표시
                    cnt++;
                }
            }
        }
        // 2차원 배열(colored) 탐색
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!colored[i][j] && !visited[i][j]){ // 물에 잠기지 않았고 방문하지 않았으면 dfs
                    ret++; // 물에 잠기지 않은 영역 개수 세기
                    dfs(i, j);
                }
            }
        }
        sol = max(sol, ret);
        if(cnt == (n * n)) break; // 백트래킹 (이미 물에 다 잠겼음으로 이 이상의 높이의 경우는 탐색하지 않음)
    }
    cout << sol << "\n";
}