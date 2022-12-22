// 트리 문제 Tip) 루트 노드부터 탐색하는게 쉽고 좋음 !! (루트노드부터 탐색하면 한번에 탐색할 수 있다)

// 리프노드(자식노드가 없음)을 코드로 표현하면 => for(int there : adj[here])이 없는 것을 의미
// 루트노드부터 탐색해나가면서 해당 노드에 연결된 노드들 확인하는 식의 방법 (리프노드를 발견하면 cnt++)

// erase를 구현하는 방법 2가지
// 1. 진짜 말그대로 지운다 
// 2. 해당 부분을 색칠하거나/탐색하지 않는다 => 추천!
#include<bits/stdc++.h>
using namespace std;
int n, r, temp, root;
vector<int> adj[54];
// dfs는 리프노드 개수를 구하는 함수이다 (그림으로 그려보면 쉬움)
// 이 로직의 반례: r(지워야할 노드)가 루트노드일 경우
int dfs(int here){ // int형 dfs
    int ret = 0; // 리프노드의 수 카운트
    int child = 0; // 자식 개수
    for(int there : adj[here]){
        if(there == r) continue; // 2번 방법으로 노드 erase구현
        ret += dfs(there); // 여기서 더해짐 
        child++;
    }
    if(child == 0) return 1; // 리프노드이면 1을 반환
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == -1)root = i;
        else adj[temp].push_back(i);
    }
    cin >> r;
    if(r == root){ // 루트노드를 지우는 경우에 대한 예외처리 (루트노드는 here에 체크가 안되는 로직으로 dfs를 짯기때문)
        cout << 0 << "\n";return 0;
    }
    cout << dfs(root) << "\n";
    return 0;
}
