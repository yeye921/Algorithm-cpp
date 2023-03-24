// 내 풀이
// 트리(그래프의 하위집합)는 3개의 특징 존재
// 1. 연결되어 있다 (모든 노드는 다른 노드와 간선으로 연결되어있다?)
// 2. 간선이 삭제되면 그래프는 더이상 연결되어 있지 않다. (즉, 어떤 노드들은 더이상 도달되지 못한다)
// 3. 2개의 노드사이에 간선이 추가될 때, 사이클이 형성된다. 사이클이 있다(A에서 B로가는 방법이 1개 이상일 때)
// 내 목표: 주어진 그래프가 트리인지 아닌지 판단!

// t: 그래프의 개수, N: 그래프의 노드 개수(1<=N<=1000), the identifier ?? 
// M: 그래프의 간선 개수(M<100만), M개의 라인 입력 받음 (간선으로 연결된 노드들)
// 그래프 전체 간선 개수 < 100만

// Q.트리를 어떤식으로 구현해야할까? -> vector를 이용한 연결리스트!
// Q.트리인지 그래프인지 어떤 방법으로 확인할건지? -> dfs로 다 연결되어 있는지 확인!

// 틀린점: dfs로 탐색 1번에 끝나는 것 외에도 E = V - 1의 특징을 만족해야 트리이다 !! (중요!!)
#include <bits/stdc++.h>
using namespace std;
int t, n, m, a, b, cnt;
bool visited[1004];
vector<int> adj[1004]; // n의 크기만큼 연결리스트 배열 생성
int dfs(int node){
    int ret = 1;
    visited[node] = 1;
    for(int next : adj[node]){
        if(!visited[next]){
            ret += dfs(next);
        }
    }
    return ret;
}
int main(){
    cin >> t;
    for(int i = 0; i < t; i++){ // 테스트케이스 문제 => 초기화 중요!
        cin >> n;
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // cnt = dfs(1);
        for(int i = 1; i <= n; i++){
            if(!visited[i]) {
                dfs(i);
                cnt++; // dfs를 한번하는지 체크하기위해 cnt로 체크함!
            }
        }
        if(cnt == 1 && (m == n -1)) cout << "tree\n"; // 여기가 포인트!! (트리 조건)
        else cout << "graph\n";

        // 초기화
        fill(visited, visited + 1004, 0);
        memset(adj, 0, sizeof(adj));
    }
}