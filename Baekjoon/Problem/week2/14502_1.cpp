// 핵심 알고리즘
// 1. 벽 세울 수 있는 경우의 수 찾기
// 2. 바이러스 퍼짐 처리
// 3. 안전 영역 크기 세기

// 초기화하는거 정말 중요함 !!! 
// => 특히 벽세우고 > 그 경우에 대한 바이러스 퍼짐 처리하고 > 다시 벽 치우고 > 바이러스 퍼짐처리 초기화

// 큰돌 풀이법과 다른 부분: temp배열로 초기화, visited대신 a[y][x] = 2처리
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, ans;
int a[10][10], temp[10][10];
vector<pi> v;

void dfs(int y, int x){
	a[y][x] = 2;
	for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
		if(nx < 0 || ny < 0 || ny >= n || nx >= m) continue;
        if(a[ny][nx] == 1 || a[ny][nx] == 2) continue;
		dfs(ny, nx);
	}
}
int solve(){
    int cnt = 0;

    // 바이러스 퍼짐 처리
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 2) dfs(i, j);
        }
    }
    // 안전영역 넓이 세기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0) cnt++;
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i  = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) v.push_back({i, j}); // 벽 세울 수 있는 경우 담기
        }
    }
    memcpy(temp, a, sizeof(a)); // temp에 a를 담음
    
    // 담은 것 중에서 3개 뽑아서 벽 처리하기
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){ // 경우의 수를 탐색하는 것이므로 테스트케이스라고 생각하면 편함!
                // 따라서 초기화에 신경써야함 !
                memcpy(a, temp, sizeof(temp)); // a에 temp를 담음

                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
                ans = max(ans, solve()); // 여기서 바이러스 퍼짐 처리 & 안전영역 넓이 세기
            }
        }
    }
    cout << ans << "\n";
}