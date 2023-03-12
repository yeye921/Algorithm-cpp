// 큰돌 풀이
// 이 문제를 보고 Connected Component 문제라는 생각이 들어야 함
// 즉, 방의 개수 = connected component의 개수
// 가장 큰 방의 넓이 = 가장 많은 요소로 이루어진 connected component 넓이

// 가장 어려운 부분: 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기 구하기 > 이거 그냥 해보면 됨 
// 위 부분을 위해 필요한 로직: 각 컴포넌트에 식별할 수 있는 id를 부여해야 함 > visited를 이용 (ex. 1번 컴포넌트는 모두 1로 표시)
//
// 큰돌 생각: 각 컴포넌트마다 넓이 저장해둔 다음에 벽을 지운다면 그 넓이끼리 더하게 함
// 내 생각: 벽들을 벡터에 담은 다음, 각 벽을 지우면서 최대 값을 갱신해나가는 완전탐색 방식 생각함

// 결론: 비트 마스킹 + DFS(connected component)
// visited[i][j]의 용도: (좌표 - 해당 영역의 id) 매핑
// compSize[cnt]의 용도: (해당 영역의 id - 해당 영역의 넓이) 매핑
#include <bits/stdc++.h>
using namespace std;   
const int dy[] = {0, -1, 0, 1}; // 이거 서북동남(0,1,2,3 > 1,2,4,8)이랑 맞추는게 좋음
const int dx[] = {-1, 0, 1, 0}; 
int visited[51][51], a[51][51], cnt, compSize[2504], n, m, mx, big; 
int dfs(int y, int x, int cnt){
    if(visited[y][x]) return 0; // dfs를 수행하는 방법2 (방법1: 아래 for문에서 if(visited[ny][nx]) continue;)
    visited[y][x] = cnt; // dfs 돌면서 각 영역을 id로 색칠해놓음
    int ret = 1; 
    for(int i = 0; i < 4; i++){
        if(!(a[y][x] & (1 << i))){ // 이동하려는 방향에 벽이 있으면 이동 못함
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            ret += dfs(ny, nx, cnt); // 자식노드에 대해서 dfs 걸음 (연결된 노드의 합을 이렇게 구함)
        } 
    } 
    return ret; 
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){ // 맵 등록
        for(int j = 0; j < n; j++){
            cin >> a[i][j]; 
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){ // 만약, 방문하지 않았다면
                cnt++; // 얘는 각 connected 컴포넌트 마다 부여할 id임!
                compSize[cnt] = dfs(i, j, cnt); // compSize는 id - 해당 컴포넌트의 넓이를 매핑함 (이거는 하나의 벽을 제거했을 때 가장 넓은 방의 크기를 구하는데 활용됨)
                mx = max(mx, compSize[cnt]); // 가장 큰 방 넓이
            } 
        }
    }
    // 한개의 벽을 부셔서 가장 큰 넓이를 구하는 로직
    // 모든 정점에 대해서 확인하는 완전탐색 방식
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // 해당 정점기준으로 아래, 오른쪽만 확인하면 됨
            if(i + 1 < m){ // 이게 진짜 중요함 (항상 방어코드로 오버플로 방지해야함)
                int a = visited[i + 1][j]; 
                int b = visited[i][j]; 
                if(a != b){ // 두 영역의 id(=cnt)가 다르면 둘을 합쳐서 넓이 구함 
                    big = max(big, compSize[a] + compSize[b]); 
                }
            }
            if(j + 1 < n){ // 오른쪽(동쪽) 영역과 넓이가 같은지 확인
                int a = visited[i][j + 1]; 
                int b = visited[i][j]; 
                if(a != b){ 
                    big = max(big, compSize[a] + compSize[b]); 
                }
            }
        } 
    } 
    cout << cnt << "\n" << mx << "\n" << big <<'\n'; 
    return 0;
}