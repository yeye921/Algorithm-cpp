// 핵심 알고리즘 
// 1. 제일 바깥 부분에서 dfs탐색 시작
// 2. 타고타고 가다 치즈 만나면 벡터에 담기
// 3. 담긴 치즈들 삭제하기
// 치즈들 다 녹을때까지 1,2,3 반복

// 출력
// 치즈가 모두 녹아서 없어지는데 걸리는 시간 출력
// 모두 녹기 한 시간 전에 남아있는 치즈조각 개수 세기

// 벡터 초기화 하는 법: v.clear();
#include <bits/stdc++.h>
using namespace std;
#define time aaa
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, time, cnt;
int a[104][104];
bool visited[104][104], check;
vector<pair<int, int>> v;
// 2번 과정 수행
void go(int y, int x){
    visited[y][x] = 1;
    if(a[y][x] == 1){ // 치즈를 만나면
        v.push_back({y, x}); // 벡터에 담고
        return; // 탐색을 종료 
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue; // 이미 방문 제외
        go(ny, nx);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    while(true){
        time++; // 반복 횟수 카운트 (즉, 치즈가 모두 녹아서 없어지는데 걸리는 시간)
        // 반복문 돌때마다 초기화 시켜야 할 것들 체크
        memset(visited, 0, sizeof(visited)); // visited 초기화
        v.clear(); // v 벡터 초기화
        cnt = 0; // 치즈 조각 개수 카운트
        check = true; // 치즈 남아있는지 체크

        go(0, 0); // 여기서 탐색하면서 치즈 담음

        // 담아온 치즈들 탐색하면서 삭제 => a[y][x] = 0 처리하기
        for(pair<int, int> pi : v){
            cnt++;
            a[pi.first][pi.second] = 0;
        }

        // 치즈가 남아있는지 체크 (2차원 배열탐색하면서 1인것 찾기)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1){
                    check = false; // 치즈가 하나라도 남아있으면 false
                    break;
                }
            }
        }
        if(check) break; // 치즈가 다 없어졌으면 반복문 탈출
    }
    cout << time << "\n";
    cout << cnt << "\n";
    return 0;
}