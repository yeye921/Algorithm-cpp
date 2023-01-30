// 트리 순회 복습
// inOrder(중위순회): 내가 중간에 깜 (왼쪽 > 자신 > 오른쪽)
// postOrder(후위순회): 자식들 먼저(왼쪽 > 오른쪽 > 자신)
// preOrder(전위순회): 나 먼저 (자신 > 왼쪽 > 오른쪽)

// 항상 루트노드부터 탐색 !
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1004]; 
int visited[1004];
void postOrder(int here){
    if(visited[here] == 0){
        if(adj[here].size() == 1) postOrder(adj[here][0]);
        if(adj[here].size() == 2){
            postOrder(adj[here][0]);
            postOrder(adj[here][1]);
        }
    }
    visited[here] = 1;
    cout << here << "\n";
}
void preOrder(int here){
    if(visited[here] == 0){
        visited[here] = 1;
        cout << here << "\n";
        if(adj[here].size() == 1) preOrder(adj[here][0]);
        if(adj[here].size() == 2){
            preOrder(adj[here][0]);
            preOrder(adj[here][1]);
        }
    }
}
void inOrder(int here){
    if(visited[here] == 0){
        if(adj[here].size() == 1){
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << "\n";
        }
        else if(adj[here].size() == 2){
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << "\n";
            inOrder(adj[here][1]);
        } else {
            visited[here] = 1;
            cout << here << "\n";
        }
    }
}
int main(){
    adj[3].push_back(6);
    adj[3].push_back(2);
    adj[6].push_back(1);
    adj[6].push_back(4);
    adj[2].push_back(5);
    adj[2].push_back(7);
    int root = 3;
    cout << "\n 트리순회 : postOrder \n"; 
    postOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : preOrder \n";
    preOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : inOrder \n";
    inOrder(root);
    return 0;
}