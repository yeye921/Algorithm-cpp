// 내 풀이 (맞음)

// 노드가 각 선거구에 포함되어 있는지 확인하는 방법
// 나) 벡터에 노드들을 담고, find함수 이용해서 해당 노드가 벡터에 포함되어 있는지 확인
// 큰돌) 따로 배열을 하나 만들어서 노드들 방문체크한 다음에 visited처럼 체크 (ex. if(comp[node]) continue;) (이 방법이 메모리도 적게 들고 강추 !!)

// dfs 종료조건/기저사례 체크하는 방법
// 나) 선택된 선거구에 담긴 노드들을 다 방문했는지 for문으로 체크 > (예제3처럼) 벡터가 비어있을 때 오류남 > X
// 큰돌) dfs를 돌면서 노드 수와 인구 수를 저장한 뒤 메인문에서 조건을 만족하는지 체크
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, num, people[13], ret=INF;
bool picked[13], visited[13];
vector<int> adj[13];
// 벡터로 한 버전
pair<int, int> dfs(int node, vector<int> v){ // 기저사례 없음 (넣으면 하나도 없을 때 오류남) > 그냥 dfs 종료 후 체크하는게 나음 !!
    visited[node] = 1;
    pair<int, int> pi = {1, people[node]};
    // 메인로직
    for(int next : adj[node]){
        if(visited[next]) continue;
        if(find(v.begin(), v.end(), next) == v.end()) continue; // 다른 선거구에 포함된 노드면 건너뜀
        pair<int, int> _temp = dfs(next, v);
        pi.first += _temp.first;
        pi.second += _temp.second;
    }
    return pi;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> people[i];
    for (int i = 1; i <= n; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> num;
            adj[i].push_back(num);
        }
    }

    for(int i = 1; i < (1 << n) - 1; i++){ // 모든 경우의 수에 대해
        vector<int> a, b;
        fill(visited, visited + 13, 0); // !! 자주 빼먹어서 틀림 (각 경우의 수에 대해 방문처리 배열 초기화 필수)
        for(int j = 0; j < n; j++){ // 뽑힌 것과 안뽑힌 것을 각 선거구로 나눔
            if(i & (1 << j)) a.push_back(j + 1);
            else b.push_back(j + 1);
        }
        // 각 선거구가 연결되었는지 확인
        pair<int, int> comp1 = dfs(a[0], a);
        pair<int, int> comp2 = dfs(b[0], b);

        // dfs에서 조건을 만족하는지 체크하기 어려우면 그냥 그 정보를 return한 후 여기서 체크해도 됨 !!!!
        // 최종 노드 수와 인구수가 맞는지 확인해야함 > 노드수와 총 인구수를 알아야 함 > 그럼 이것을 pair로 return할 수 밖에 없음
        if(comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second));
    }
    // 두 선거구로 나눌 수 없으면 -1, 있으면 인구 차이의 최솟값 출력
    cout << (ret == INF ? -1 : ret) << "\n";
    return 0;
}