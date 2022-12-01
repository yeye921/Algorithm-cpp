// DFS를 구현하는 방법 2가지 - 암기!!
// 1. 돌다리 두들겨 보고 건너기
void dfs(int here){
    visited[here] = 1;
    for(int there : adj[here]){
        if(visited[there]) continue; // 방문되어 있는지 체크하고 dfs 호출
        dfs(here);
    }
}
// 2. 무조건 dfs호출하고 나서 체크
void dfs(int here){
    if(visited[here]) return; // 만약 방문되어 있다면 종료
    visited[here] = 1;
    for(int there : adj[here]){
        dfs(there);
    }
}