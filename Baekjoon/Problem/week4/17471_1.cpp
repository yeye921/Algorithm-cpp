// 이렇게 dfs에서 완탐 진행하는 것도 가능함 !!! (블로그 풀이 참고)

// 노드가 각 선거구에 포함되어 있는지 확인하는 방법
// 나) 벡터에 노드들을 담고, find함수 이용해서 해당 노드가 벡터에 포함되어 있는지 확인
// 큰돌) 따로 배열을 하나 만들어서 노드들 방문체크한 다음에 visited처럼 체크 (ex. if(comp[node]) continue;) (이 방법이 메모리도 적게 들고 강추 !!)

// dfs 종료조건/기저사례 체크하는 방법
// 나) 선택된 선거구에 담긴 노드들을 다 방문했는지 for문으로 체크 > (예제3처럼) 벡터가 비어있을 때 오류남 > X
// 큰돌) dfs를 돌면서 노드 수와 인구 수를 저장한 뒤 메인문에서 조건을 만족하는지 체크
#include <bits/stdc++.h>
using namespace std;
int n, people[13], selected[13], visited[13];
vector<int> adj[13];
// 뽑는 방법은 이것 말고도 비트마스킹 모든 경우의 수 구하는 법으로 하는게 더 나을 수 있음
// dfs 완전탐색을 통해 2개의 선거구로 나누는 방식 구현
// 내가 모르겠는 것은 뽑는 방법이 아니라, 뽑아져 있는 걸 가지고 연결된 컴포넌트인지 확인하는 것 !!!
void dfs(int node){
    
    visited[node] = 1;
    dfs(node);
    visited[node] = 0;
    // 0을 색칠함
    // dfs 진헹
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> people[i];
    for(int i = 0; i < n; i++){
        int num = 0;
        cin >> num;
        for(int j = 0; j < num; j++){
            // 각 구역에 인접한 구역 입력 받음
            int node = 0;
            cin >> node;
            adj[i].push_back(node - 1);
        }
    }
    dfs(0);

    return 0;
}