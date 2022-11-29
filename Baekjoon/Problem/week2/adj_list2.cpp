// 인접리스트를 기반으로 탐색하기 예제
// 0번부터 방문 안 한 노드를 찾고 해당 노드부터 방문, 연결된 노드를 이어서 방문해서 출력하는 재귀함수 만듬
// 또한, 정점을 방문하고 다시 방문하지 않게 만듬
#include <bits/stdc++.h>
using namespace std;
const int v = 10;
vector<int> adj[v];
int visited[v];
void go(int idx){
    cout << idx << "\n";
    visited[idx] = 1;
    for(int there : adj[idx]){ // 이 정점에 연결된 정점들을 탐색
        if(visited[there]) continue;
        go(there);  // 방문하지 않았다면 방문 !
    }
    return;
}
int main(){
    adj[1].push_back(2); adj[2].push_back(1);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[3].push_back(4); adj[4].push_back(3);

    for(int i = 0; i < v; i++){
        if(adj[i].size() && visited[i] == 0){ // 만약, 연결된 정점이 있고 해당 정점을 방문하지 않았으면
            go(i); // 방문 !
        }
    }
}