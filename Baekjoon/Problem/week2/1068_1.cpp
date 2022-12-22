// 벡터의 특정 값 지우는 법: 
// 1) v.erase(v.begin() + i) // i번째 원소 삭제 (인덱스로 삭제)
// 2. v.erase(remove(v.begin(), v.end(), 지울 값), v.end()) // 특정 값 삭제
// 벡터 배열(vector<int> v[10]) vs 2차원 벡터(vector<vector<int>> v) 차이점 알아두기

// void형 dfs로 구현한 점이 이전 풀이와 다름
#include <bits/stdc++.h>
using namespace std;
int n, r, temp, root, cnt;
vector<int> adj[54];
// 트리 문제는 항상 루트노드부터 탐색해야됨 !!
// dfs랑 여러가지 변수들이 어떻게 동작하는지 아직 감이 안옴 => 출력해보자
void dfs(int here){
    int child = 0;
    for(int there : adj[here]){
        if(there == r) continue;
        dfs(there);
        child++;
    }
    if(child == 0) cnt++; 
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == -1) root = i;
        else adj[temp].push_back(i);
    }
    cin >> r;
    if(r == root){
        cout << "0\n"; return 0;
    }
    dfs(root);
    cout << cnt << "\n";
    return 0;
}
