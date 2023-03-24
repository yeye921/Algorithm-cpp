// 큰돌 풀이
// 트리를 잘 알고있냐는 취지의 문제

// 트리의 특징
// E = V - 1, 트리의 노드들은 하나로 엮여있다(=connected component, 유일무이), 부모, 자식 계층 구조를 가진다

// 트리인지 그래프인지 체크하는 로직
// m1) dfs 한번으로 모든 정점을 방문할 수 있는지 체크
// m2) E = V - 1의 특징을 만족하는지 체크
#include <cstdio>
#include <vector>
using namespace std; 
int t, n, m, a, b, visited[1004], cnt; 
vector<int> adj[1004]; 
void dfs(int here){
    visited[here] = 1; 
    for(int there : adj[here]){
        if(!visited[there]) dfs(there); 
    } 
    return;
} 

int main(){
    scanf("%d\n", &t); 
    while(t--){
        // 테스트 케이스 문제니까 초기화해줌
        for(int i = 0; i < 1004; i++)adj[i].clear();
        fill(visited, visited + 1004, 0);

        cnt = 0;  
        scanf("%d %d", &n, &m); 
        for(int i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            // 양방향 간선 연결
            adj[b].push_back(a);
            adj[a].push_back(b);  
        }
        
        for(int i = 1; i <= n; i++){
            if(!visited[i]) {
                dfs(i);
                cnt++; // dfs를 한번하는지 체크하기위해 cnt로 체크함!
            }
        }
        // dfs 한번으로 모든 노드 탐색 되는지 & E = V - 1의 특징을 만족하는지 체크!
        if(m == n - 1 && cnt == 1) puts("tree");
        else {
            puts("graph");
        } 
    }
} 