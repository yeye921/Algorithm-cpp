// 내 풀이 (큰돌 풀이와 거의 똑같음)
#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, cnt, ret;
bool visited[10004];
vector<int> adj[10004];
vector<int> v;
void dfs(int node){ // 이 정점에 연결된 노드 개수 카운트
    visited[node] = 1;
    // cout << node << "\n";
    for(int there : adj[node]){
        if(visited[there]) continue; // 이미 방문했으면 건너뜀
        cnt++;
        dfs(there);
    }
}
int main(){
    cin >> n >> m;
    // 신뢰하는 관계처리
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[b].push_back(a);
    }
    // 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 출력 => 어떻게하지?? => 더 나은 방법 생각해보기
    // m1) 각 정점에서 탐색시작했을 때 연결된 노드개수 카운트해서 제일 많은거 출력 => 최악의 경우 그래프 탐색 1만번 일어남
    for(int i = 1; i <= n; i++){
        // 테스트케이스처럼 초기화해야함 (중요 !!)
        cnt = 0; // 연결된 노드 개수 카운트
        memset(visited, 0, sizeof(visited)); // visited 배열 초기화
        dfs(i);
        v.push_back(cnt);
        ret = max(ret, cnt);  // 최대값을 찾음
    }
    // 그 최대 값에 해당하는 노드들을 출력 (오름차순으로)
    for(int i = 0; i < n; i++){
        if(v[i] == ret) cout << i + 1 << " ";
    }
    cout << "\n";
    return 0;
}