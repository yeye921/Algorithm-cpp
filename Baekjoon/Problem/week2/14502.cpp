// 조건: 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다 !!! => 이거 빠뜨리면 안됨
// 목표: "얻을 수 있는 안전 영역의 최대 크기"를 출력한다
// 벽을 세울 수 있는 모든 경로를 탐색하면서 모든 경우의 수 중에 0의 개수가 가장 많은 것을 출력하면 됨

// 완전 탐색할 때는 해제해주는게 중요함 => 각각의 경우의 수를 계산할 때마다 초기화를 해주는 것이 중요하다! (like 테스트케이스)

// 2차원 배열 복사: memcpy(a, temp, sizeof(a)) // a를 temp에 복사
// 배열 초기화 하는 법: fill(&a[0][0], &a[n][m], 초기화하는 값) 또는 memset(배열이름, 0또는 -1, 배열의 크기)
// 1또는 10 이런 숫자는 절대 memset으로 초기화 못함!! 
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m, a[10][10];
vector<pi> v;
bool visited[10][10];
// visited 처리하는게 의미가 있을까 ?? => 이미 방문했으면 빈벽이 아닐거잖아!! => 방문처리 대신에 바이러스 처리 해줘야함!!
// 큰돌님은 바이러스 처리를 visited로 했음 (나는 a[y][x] == 2처리로 했음)
// x, y순으로 구현된 거 주의 (x가 행으로 들어감)
void dfs(int x, int y){
	if(a[x][y] == 1 || visited[x][y]) return; // 방문했거나 벽이면 (일단 호출하고 조건체크하는 방식의 dfs)
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		dfs(nx, ny);
	}
}
int solve(){
    // 2. 바이러스 퍼짐 처리
	memset(visited, 0, sizeof(visited)); // 해당 경우의 수(테스트케이스) 처리 => 초기화 중요 !
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 2) dfs(i, j);
		}
	}

    // 3. 안전영역 크기 세기
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!visited[i][j] && a[i][j] == 0) ans++;
		}
	}
	return ans;
}
int main(){
	cin >> n >> m;

    // 1. 벽 3개 세우기 (2주변에 있는 1중에 3개 뽑아야 함)
    // 벽을 세우는 모든 경우의 수를 생각해야함 (무식하게 푸려고 함) => 순열과 조합을 생각해야함
    // 문제의 범위를 봐야 함 => 64 C 3 => 3만6천정도 => 괜찮다! (1000만이나 1억이하정도는 무식하게 풀어도 괜찮다!)
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
			if(!a[i][j]) v.push_back(pi(i, j)); // 벽을 세울 수 있는 좌표(빈칸)를 v에 담음
		}
	} 
    assert(v.size() >= 3); // 신경 안써도 됨
	int ans = 0;
	// 빈칸 좌표들 중 3개 뽑는 경우의 수 (= v에서 3개 뽑을 경우의 수) => 3중 for문으로 구현
	for(int i =0 ; i < v.size(); i++){
		for(int j = 0; j < i; j++){
			for(int k = 0; k < j; k++){
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1; // 벽을 세우고
				ans = max(ans, solve()); // solve함수 호출 => 해당 경우의 바이러스 퍼졌을 때 안전영역 크기 구하기
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0; // 다시 벽을 해제함
			}
		}
	}
	cout << ans;
}