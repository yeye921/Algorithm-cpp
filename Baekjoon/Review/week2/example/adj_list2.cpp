#include <bits/stdc++.h>
using namespace std;
const int v = 10;
vector<int> adj[v];
int visited[v];
void go(int idx){
    visited[idx] = 1;
    for(int there : adj[idx]){ // 해당 정점에 연결된 정점들을 탐색
        if(visited[there]) continue;
        cout << idx << " : " << there << "\n";
        else go(there);
    }
    return;
}
int main(){
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    for(int i = 0; i < v; i++){ // 연결리스트 탐색
        if(visited[i] == 0 && adj[i].size()){ // 연결된 정점이 있고 방문하지 않았으면
            go(i); // 방문 !
        }
    }
    
}