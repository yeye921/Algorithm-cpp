// 노드 하나를 지웠을 때 남은 트리에서 리프 노드의 개수를 구하는 프로그램
// => 그래프를 탐색하면서 리프노드를 만나면 카운트하자 (삭제해야하는 노드는 건너뜀)

// 노드 삭제 => 방문하지 않음으로 구현
// visited 배열은 필요하지 않음
#include <bits/stdc++.h>
using namespace std;
int n, temp, root, node, cnt;
vector<int> adj[53];
// 디버깅할때는 제일 아래에 있는 노드부터 타고 올라간다고 생각하면 쉬움!
// 이 dfs 로직의 함정: 루트노드는 삭제하지 못함 !! => 따로 처리가 필요함
// void dfs(int here){
//     int child = 0;
//     visited[here] = 1;
//     for(int there : adj[here]){
//         if(visited[there] || there == node) continue;
//         child++;
//         dfs(there);
//     }
//     if(child == 0) cnt++; // 리프노드개수 카운트
// }
int dfs(int here){
    int ret = 0;
    int child = 0;
    for(int there : adj[here]){ 
        if(there == node) continue; // 이미 방문한 노드거나 삭제할 노드면 방문하지 않음
        child++;
        ret += dfs(there);
    }
    if(child == 0) return 1;
    return ret;
}
int main(){
    cin >> n;
    // 트리 입력
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == -1) root = i;
        else adj[temp].push_back(i);
    }
    cin >> node; // 삭제할 노드 입력 받음
    if(node == root){
        cout << "0\n";
        return 0;
    }
    cout << dfs(root) << "\n"; // 그래프 탐색은 항상 루트노드부터 !
    // cout << cnt << "\n";
    return 0;
}