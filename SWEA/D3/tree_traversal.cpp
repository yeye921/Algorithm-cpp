// 트리 순회의 3가지 방법
// 1. postOrder(후위순회): 자식들 먼저, 부모 나중 탐색
// 2. preOrder(전위순회): 부모 먼저, 자식 나중 탐색
// 3. inOrder(중위순회): 왼쪽 자식, 부모, 오른쪽 자식순으로 탐색

// +) 이미 방문했던 노드인지 체크하는게 중요함!
#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[1004];
int visited[1004];
void postOrder(int here){
    if(visited[here] == 0){ // 공통: 이미 방문한 노드인지 체크
        if(adj[here].size() == 1) postOrder(adj[here][0]); // 자식노드가 하나일 경우
        if(adj[here].size() == 2){ // 자식노드가 둘일 경우
            postOrder(adj[here][0]); // 왼쪽 노드 탐색
            postOrder(adj[here][1]); // 오른쪽 노드 탐색
        }

        visited[here] = 1; // 부모 노드 탐색
        cout << here << " ";
    }
}
void preOrder(int here){
    if(visited[here] == 0){ // 공통
        visited[here] = 1;
        cout << here << " ";
        
        if(adj[here].size() == 1) preOrder(adj[here][0]); // 자식노드가 하나일 경우
        if(adj[here].size() == 2){ // 자식노드가 둘일 경우
            preOrder(adj[here][0]); // 왼쪽 노드 탐색
            preOrder(adj[here][1]); // 오른쪽 노드 탐색
        }
    }
}
void inOrder(int here){
    if(visited[here] == 0){ // 공통
        if(adj[here].size() == 1){
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << " ";
        }
        else if(adj[here].size() == 2){
            inOrder(adj[here][0]);
            visited[here] = 1;
            inOrder(adj[here][1]);
        }
        else { // 자식이 하나도 없을때
            visited[here] = 1;
            cout << here << " ";
        }
    }
}
int main(){
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    int root = 1; // 트리 탐색은 항상 루트노드부터!

    cout << "postOrder \n";
    postOrder(root); memset(visited, 0, sizeof(visited));

    cout << "\npreOrder \n";
    preOrder(root); memset(visited, 0, sizeof(visited));

    cout << "\ninOrder \n";
    inOrder(root); memset(visited, 0, sizeof(visited));
    return 0;
}