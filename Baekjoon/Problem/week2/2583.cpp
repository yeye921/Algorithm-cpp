// 실버 1이지만 은근 까다로운 문제 !!
// connected component 문제 => dfs가 코드가 짧으므로 dfs로 풀기

// 출제자 특: DFS를 어렵게 하려고 할 때 입력을 이상하게 준다 !!
// 이 문제의 핵심: DFS가 아니라 이 사각형의 넓이를 무엇으로 구할거냐, 주어진 조건에 대해서 어떻게 예외처리 할 것이냐
// 왼쪽 아래 점의 개수 = 사각형의 개수

// 좌표평면만 회전하면 전형적인 DFS 문제다 !
// 좌표가 이상하지만 뒤집어지더라도 영역 크기는 동일하니 문제 없다 !

// int형 dfs에 대한 숙달 필요함!
#include<bits/stdc++.h> 
using namespace std;  
#define y1 aaaa // 변수명 에러날 때 해줘야 하는 것
int a[104][104], m, n, k, x1, x2, y1, y2, visited[104][104];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
vector<int> ret; 
int dfs(int y, int x){ // 넓이변수 대신에 int형 dfs사용 (변수 적게 사용하는게 좋음)
    visited[y][x] = 1; 
    int ret = 1; 
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        if(ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] == 1) continue; 
		if(a[ny][nx] == 1) continue;
        ret += dfs(ny, nx);
    } 
    // cout << y << " : " << x << " : " << ret << "\n";
    return ret; 
}
int main() { 
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> k; 

    // (x, y)가 주어지는게 아니라 x,y좌표가 주어지는 것임 !! (이걸 깨닫는게 중요)
    for(int i = 0; i < k; i++){
        cin >> x1 >> y1 >> x2 >> y2;  
        for(int x = x1; x < x2; x++){ // 항상 행기준으로 탐색 !
            for(int y = y1; y < y2; y++){
                a[y][x] = 1;
            }
        }
    }
    // 디버깅 용
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != 1 & visited[i][j] == 0) { // 색칠되어있지 않고 & 방문되지 않았으면
                ret.push_back(dfs(i, j));
            }
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n"; // connected component의 개수
    for(int a : ret) cout << a << " "; // 각 component의 넓이
    return 0; 
}