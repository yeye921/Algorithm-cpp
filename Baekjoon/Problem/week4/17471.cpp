// 큰돌 풀이
// 2개의 connected component를 만드는 문제

// 내가 생각한 로직이랑 큰돌 로직이랑 똑같음 
// 색칠하면서 모든 경우의 수를 체크하고 > 2개의 선거구로 쪼개지는지 확인 > 두 선거구 인구수 차이 최소값 갱신
// (색칠: 모든 구역을 0또는 1로 색칠함 = 자동으로 2개의 구역으로 나눠짐)
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;  
int n, a[11], m, temp, ret=INF, comp[11], visited[11];
vector<int> adj[11]; 
// dfs함수의 반환형을 void, vector 등등 자유롭게 다룰 수 있어야 함 !!
pair<int, int> dfs(int node, int value){
    cout << "node: " << node << "\n";
    visited[node] = 1; 
    pair<int, int> ret = {1, a[node]}; // {노드/컴포넌트의 자식수, 연결된 컴포넌트의 총 인구수}
    for(int there : adj[node]){ // 해당 노드에 연결된 정점 탐색
        if(comp[there] != value) continue; // 내가 인자로 받은 value와 색깔이 다르면 건너뜀
        if(visited[there]) continue; 
        pair<int, int> _temp = dfs(there, value); // 같으면 dfs를 이어나감
        ret.first += _temp.first; 
        ret.second += _temp.second;  
    }
    return ret;
}  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; 
    for(int i = 1; i <= n; i++){
        cin >> a[i];  
    }
    // 양방향 간선을 만듬
    for(int i = 1; i <= n; i++){
        cin >> m; 
        for(int j = 0; j < m; j++){
            cin >> temp; 
            adj[i].push_back(temp); 
            adj[temp].push_back(i); // Q. 이렇게 하면 두 번씩 들어가는거 아님??
        } 
    }
    // n개의 노드 중에서 1~(n-1)개를 뽑는 경우의 수 (뽑아진 지역/안뽑아진 지역으로 선거구를 나눔)
    for(int i = 1; i < (1 << n) - 1; i++){ // 모든 경우의 수에 대해 탐색 (0, n개 뽑는 경우는 제외) 
        // 각 경우의 수마다 초기화
        fill(comp, comp + 11, 0); 
        fill(visited, visited + 11, 0);

        int idx1 = -1, idx2 = -1; // 각 선거구를 탐색할 스타트 지점을 의미함
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){comp[j + 1] = 1; idx1 = j + 1;} // 켜진 노드에 대해 comp[idx+1] = 1로 색칠함, idx1에 노드번호 저장 
            else idx2 = j + 1; // 꺼져있으면 comp에 처리할 필요 없음
        }
        // 한 경우의 수마다 dfs 딱 두번만 돌림 (각 선거구가 연결되어 있는지 확인)
        pair<int, int> comp1 = dfs(idx1, 1); // comp라는 배열이 1로 색칠되어 있으니까 > 1로 색칠한 선거구에 대한 dfs 진행 (각 구역이 연결되어 있는지 확인)
        pair<int, int> comp2 = dfs(idx2, 0); // 안뽑은 것들(0)에 대한 dfs 진행
        if(comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second)); // 정확히 2개로 나누어져있는지를 체크함 (3개일 경우 n이 안나옴)
    } 
    cout << (ret == INF ? -1 : ret)<< "\n";
}