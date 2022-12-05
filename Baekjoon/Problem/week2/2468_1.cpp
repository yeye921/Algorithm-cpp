// 2차원 배열 초기화하는 법 => fill(&visited[0][0], &visited[n][n], 0) 이용

// set은 자동으로 데이터를 정렬된 상태로 유지시켜 줌
// set의 원소 삭제: set.erase(key)

// 예외처리: 아무 지역도 물에 잠기지 않을 수 있다
#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, max_val, cnt, ret, height;
int a[104][104], visited[104][104];
set<int> st;
void dfs(int y, int x){
    visited[y][x] = 1;
    // cout << cnt << " : " << y << ", " << x << "\n"; // for 디버깅
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(a[ny][nx] > height && !visited[ny][nx]){
            dfs(ny, nx);
        }
    }
}
int main(){
    cin >> n;

    // 2차원 배열 입력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            st.insert(a[i][j]);
        }
    }
    if(st.size() == 1){
        cout << 1 << "\n";
        return 0;
    }

    // 높이의 경우의 수
    for(int i : st){
        // 초기화 중요 !!
        cnt = 0;
        fill(&visited[0][0], &visited[n][n], 0); // visited 배열 초기화
        if(i == *max_element(st.begin(), st.end())) break; // 최대값은 pass
        height = i;

        // cout << "높이 " << height << "\n";

        // 해당 높이 이상인 지점을 dfs 적용함
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] > height && visited[i][j] == 0){
                    cnt++; 
                    dfs(i, j);  // i>j 순서로 들어갈 수 있는 이유: 행 > 열순으로 탐색!
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret << "\n";
}