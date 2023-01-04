// [순회의 종류]
// 후위: 자식들부터 방문
// 전위: 자기자신부터 방문
// 중위: 왼 > 자신 > 오 (중간에 꼈음)
// 레벨: BFS

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1004]; // 인접리스트를 기반으로 구현
int visited[1004]; // 방문처리 배열

void postOrder(int here){
    if(visited[here] == 0){ // 방문하지 않았다면
        if(adj[here].size() == 1) postOrder(adj[here][0]); // 자식이 하나라면 
        if(adj[here].size() == 2){
            postOrder(adj[here][0]); // 0: 왼쪽 자식노드를 의미
            postOrder(adj[here][1]); // 1: 오른쪽 자식노드를 의미
        }
        visited[here] = 1;
        cout << here << ' ';
    }
}
void preOrder(int here){ // postOrder랑 코드 배치 순서만 다르고 똑같음
    if(visited[here] == 0){
        visited[here] = 1;
        cout << here << ' ';
        if(adj[here].size() == 1) preOrder(adj[here][0]);
        if(adj[here].size() == 2){
            preOrder(adj[here][0]);
            preOrder(adj[here][1]);
        }
    }
}
void inOrder(int here){ // 왼쪽이 있는지, 오른쪽이 있는지 판단해야해서 코드가 김
    if(visited[here] == 0){
        if(adj[here].size() == 1){
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << ' ';
        } else if(adj[here].size() == 2){ // 자식이 둘이면
            inOrder(adj[here][0]); // 왼쪽 방문
            visited[here] = 1; // 자기자신 방문
            cout << here << ' ';
            inOrder(adj[here][1]); // 오른쪽 방문
        } else { // 자식이 하나도 없으면
            visited[here] = 1; 
            cout << here << ' ';
        }
    }
}
int main(){
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    int root = 1; // 루트노드부터 트리순회
    cout << "트리순회: postOrder \n";
    postOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n트리순회: preOrder \n";
    preOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n트리순회: inOrder \n";
    inOrder(root);
    return 0; 
}