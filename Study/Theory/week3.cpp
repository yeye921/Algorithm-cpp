// bfs (너비우선탐색)
// 어떤 정점에서 시작해 다음 깊이의 정점으로 이동하기전,
// 현재 깊이의 모든 정점을 탐색하며 방문한 정점은 다시 방문하지 않는 알고리즘
// => 같은 가중치를 가진 그래프에서 최단거리 알고리즘으로 쓰임

// Q. 시작지점이 다수라면?
// 처음 큐에 푸시하는 지점도 다수가 되어야 하며 해당 지점들의 visited를 모두 1로 만들면서 시작해야함
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100];
int visited[100];
int nodeList[] = {10, 12, 14, 16, 18, 20, 22, 24};
void bfs(int here){
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while(q.size()){
        int here = q.front();
        q.pop();
        for(int there : adj[here]){ // here에 연결된 정점들 탐색
            if(visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }

}
int main(){
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);
    bfs(10);
    for(int i : nodeList){
        cout << i << " : " << visited[i] >> "\n";
    }
    cout << "10번으로부터 24번까지 최단거리는 : " << visited[24] - 1 << "\n";
    return 0;
}

