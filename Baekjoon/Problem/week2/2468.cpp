// connected component 문제 => dfs로 풀기

// 내가 푼 방식 => 요소들의 값을 set으로 받아 set의 원소들을 depth로 설정 & 예외 처리
// 큰돌 방식 => depth를 1~100로 설정
#include<bits/stdc++.h>
using namespace std;   
int a[101][101], visited[101][101], n, ret = 1;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
void dfs(int y, int x, int d){ // 함수 인자로 depth 추가함
    visited[y][x] = 1; 
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue; 
        if(!visited[ny][nx] && a[ny][nx] > d) dfs(ny, nx, d);
    }
    return;
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);   
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int d = 1; d < 101; d++){ // 모든 depth를 검토 (depth = 테스트 케이스)
        // 테스트 케이스 문제는 초기화가 중요!
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0); 
        int cnt = 0;  
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] > d && !visited[i][j]) { // 높이 초과 & 방문 안한 경우
                    dfs(i, j, d);
                    cnt++;
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret << '\n';
    return 0; 
}
