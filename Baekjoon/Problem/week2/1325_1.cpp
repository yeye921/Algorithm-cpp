// 큰돌 풀이
// 어떤 정점에서부터 탐색시작해야 가장 많은 노드들을 탐색할 수 있는가 => 루트노드

// dfs 탐색하려고 함 > 문제 범위 체크(1만) > 최악의 경우 시간복잡도는 n^2 즉, 1억
// 지금까지 배운 알고리즘을 바탕으로 이 문제를 풀 수 있는 방법은 dfs밖에 없음 > 근데 시간복잡도가 1억이야 이게될까? 라고 생각하면서 풀어야함

// int형 dfs VS void형 dfs 비교 알아두기
// m1) 이렇게 void형 dfs를 만들고 전역변수 cnt로 카운트 할 수 있음
// void dfs(int here){
//     cnt++;
//     visited[here] = 1;
//     for(int there : v[here]){
//         if(visited[there]) continue;
//         dfs(there);
//     }
//     return;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> v[10001];
int dp[10001], mx, visited[10001], n, m, a, b; // dp: 해당 노드(idx)부터 탐색했을때 방문할 수 있는 노드의 수 저장
// m2) int형 dfs를 이용해서 cnt를 사용하지 않고 카운트 할 수도 있음 (= here로 부터 탐색할 수 있는 개수)
int dfs(int here){ // here부터 시작해서 탐색할 수 있는 모든 노드의 개수를 셈
    int ret = 1;
    visited[here] = 1;
    for(int there : v[here]){
        if(visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}
int main() { 
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cin >> n >> m;  
    // 그래프를 만듬
	while (m--) {
     	cin >> a >> b;  
	    v[b].push_back(a);
	} 
	for (int i = 1; i <= n; i++) { // 이 범위가 은근 중요함 !!
		memset(visited, 0, sizeof(visited)); // 초기화 (계속해서 dfs를 할 것이기 때문, like 테스트케이스)
		dp[i] = dfs(i);  // dp는 하나의 배열 (i부터 탐색했을때 탐색할 수있는 노드의 개수를 담음)
		mx = max(dp[i], mx);
	} 
	for (int i = 1; i <= n; i++) if (mx == dp[i]) cout << i << " "; 
	return 0;
}