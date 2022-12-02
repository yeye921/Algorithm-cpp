#include <bits/stdc++.h>
using namespace std;
const int max_n = 10; // 정점 개수
int visited[max_n];
vector<int> adj[max_n];
void go(int from){
    cout << from << "\n";
    visited[from] = 1; // 방문처리 함
    for(int there : adj[from]){ // 해당 노드에 연결된 노드를 방문
        if(visited[there] == 0){
            go(there);
        }
    }
}

int main(){
    // 1. 연결리스트 생성
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(5);
    adj[5].push_back(3);

    // 2. 0번부터 방문안한 노드 찾고 해당 노드부터 방문, 연결된 노드를 이어서 방문
    for(int i = 0; i < max_n; i++){ // 노드들 탐색
        if(visited[i] == 0) go(i);
    }

}