// 큰돌 풀이로 다시 풀어봄
// 인덱스/노드번호 1부터 시작하는걸로 전부 맞춰줘야 함 !! (안그러면 틀림)
// ex. people배열 인덱스, adj인덱스, ..
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, node, people[13], ret=INF, comp[13];
bool visited[13];
vector<int> adj[13];
pair<int, int> dfs(int node, int val){
    visited[node] = 1;
    pair<int, int> ret = {1, people[node]};
    for(int next : adj[node]){
        if(visited[next]) continue;
        if(comp[next] != val) continue;
        pair<int, int> _temp = dfs(next, val);
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> people[i];
    for(int i = 1; i <= n; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> node;
            adj[i].push_back(node);
        }
    }
    // 선거구를 2개로 나누어서 각 선거구가 연결되어 있는지 확인
    // 내 방식: 뽑은 것을 벡터에 담고 dfs해서 벡터에 담긴게 전부 방문처리되었는지 확인하는 로직
    // 큰돌 방식: 풀이는 외웠지만 어떻게 생각해냈는지는 모르겠음
    for(int i = 1; i < (1 << n) - 1; i++){
        // 각 경우의 수 (각 경우에 대해 dfs 진헹)
        int idx1 = -1, idx2 = -1;
        fill(visited, visited + 13, 0);
        fill(comp, comp + 13, 0);

        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                comp[j + 1] = 1;
                idx1 = j + 1;
            }
            else idx2 = j + 1;
        }
        pair<int, int> comp1 = dfs(idx1, 1);
        pair<int, int> comp2 = dfs(idx2, 0);   
        if(comp1.first + comp2.first == n){ret = min(ret, abs(comp1.second - comp2.second));}         
    }
    cout << (ret == INF ? -1 : ret) << "\n";
    return 0;
}