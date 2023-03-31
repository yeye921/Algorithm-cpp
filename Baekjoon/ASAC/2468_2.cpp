// 어떤 지역의 높이 정보가 주어졌을 때, 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 계산하기
// 풀이 방법: 각 높이에 대해 물에 잠기지 않은 점들의 dfs 횟수 구하면 됨
// 완점 탐색 + 백트래킹 문제

// +) set 자료구조는 인덱스로 접근할 수 없다!

// 내가 자주 실수하는 것!!: fill은 항상 전체를 초기화해야한다 (가입력 받은 부분만 초기화할 수 없음 !!)
// fill(&colored[0][0], &colored[0][0] + n*n, 0) => 틀림
// fill(&colored[0][0], &colored[n][n], 0) => 맞음 
#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int n, num, _map[max_n][max_n], colored[max_n][max_n], mn, mx, sol=1;
bool visited[max_n][max_n];
set<int> st;
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
            st.insert(num);
        }
    }

    // 높이의 경우의 수 구하기 
    // m1) 좌표에 나오는 높이들을 벡터에 저장해서 최솟값부터 탐색하면서 하는 방법
    // 아무 지역도 물에 잠기지 않을 수도 있음(개수=1)으로 sol=1로 초기화해서 갱신함 
    for(int dep : st){ // 테스트케이스는 초기화가 중요
        fill(&colored[0][0], &colored[0][0] + max_n*max_n, 0); // 이렇게 배열 전체 크기를 초기화 시켜줘야 함
        fill(&visited[0][0], &visited[0][0] + max_n*max_n, 0);
        // 2차원 배열(colored) 탐색
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(_map[i][j] <= dep){
                    colored[i][j] = 1;
                }
            }
        }
        int cnt = 0; // 물에 잠기지 않는 영역의 개수
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && !colored[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        sol = max(sol, cnt);
    }
    cout << sol << "\n";
}