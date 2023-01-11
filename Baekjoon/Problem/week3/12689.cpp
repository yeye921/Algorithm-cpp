//큰돌 풀이
// 이 문제는 BFS로 풀어야 함 (BFS 로직: visited처리 > q.push > while(q.size())) (+) DP로도 풀 수 있음)
// ex. 18 6 2 => 9 3 1 => 0 0 0
// ex.        => 9 5 0 => 0 2 0
// 가중치가 같은 그래프 내, 이렇게 레벨별로 탐색하면 => 최단거리 배열 만들 수 있음
// !! 레벨별로 탐색하다가 어떤 정점에서 scv가 모두 소진되었으면 탐색 종료하면 됨

// 3개의 변수 담아야 함 => tuple 또는 struct(추천) 사용
#include <bits/stdc++.h> 
using namespace std;
const int INF = 987654321;
int a[3], n, visited[64][64][64]; // 각 scv의 잔여 능력치를 다음과 같이 visited배열로 표현함
int _a[6][3] = { // 때리는 경우의 수 = 6개
	{9, 3, 1}, 
	{9, 1, 3}, 
	{3, 1, 9}, 
	{3, 9, 1}, 
	{1, 3, 9}, 
	{1, 9, 3}
};
struct A{
    int a, b, c; 
}; 
queue<A>q; 
int solve(int a, int b, int c){ // scv를 받음
    visited[a][b][c] = 1; // 어떻게 이렇게 표현할 생각을 하지 ..? => 포인트 !
    q.push({a, b, c}); 
    while(q.size()){
        int a = q.front().a; 
        int b = q.front().b; 
        int c = q.front().c; 
        q.pop();
        if(visited[0][0][0]) break; // 만약 (0, 0, 0)(=목표)을 방문하면 탐색 종료
        for(int i = 0; i < 6; i++){
            // 트랜잭션에서도 많이 쓰이는 코드 => 음수가 되는걸 막아줌 (왜? 음수는 배열에 인덱싱할 수 없음)
            int na = max(0, a - _a[i][0]); // 음수를 0으로 치환해줌 (꿀팁!)
            int nb = max(0, b - _a[i][1]); 
            int nc = max(0, c - _a[i][2]); 
            if(visited[na][nb][nc]) continue; // 이런 경우가 존재할까..? => 필수!
            visited[na][nb][nc] = visited[a][b][c] + 1; // 최단거리 배열 만듬
            q.push({na, nb, nc}); 
        }
    }
    return visited[0][0][0] - 1;   
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n; 
	for(int i = 0; i < n; i++) cin >> a[i]; 
	cout << solve(a[0], a[1], a[2]) << "\n"; 
    return 0;
}
