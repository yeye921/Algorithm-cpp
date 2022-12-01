// BFS: 가중치가 같은 그래프 내에서 최단거리 알고르즘으로 쓰임
// visited배열로 최단거리 배열을 만듬

// 10번 정점부터 탐색하는 BFS 코드
// bfs => level별로 탐색해야함 => 선입선출 => queue 이용!
#include<iostream>
using namespace std;
vector<int> adj[100];
int visited[100];
int nodeList[] = {10, 12, 14, 16, 18, 20, 22, 24}; // 정점들
void bfs(int here){ // 이건 한번만 호출됨
    queue<int> q;
    visited[here] = 1; // 여기서 시작해서 연결된 것들 탐색
    q.push(here);

    // 큐가 빌 때까지 반복
    while(q.size()){
        int here = q.front(); q.pop();
        for(int there : adj[here]){
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

    bfs(10); // bfs 돌린 다음 나온 최단거리 배열 출력
    for(int i : nodeList){
        cout << i << " : " << visited[i] << "\n";
    }
    cout << "10뱐으로부터 24번까지 최단거리는 : " << visited[24] - 1 << "\n";
    return 0;
}