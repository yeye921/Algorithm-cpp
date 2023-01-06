// 큰돌 풀이
// 단순 구현 문제
// 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다
// => connected component가 생각나야함 !
#include <bits/stdc++.h>
using namespace std;
int visited[54][54], a[54][54], n, l, r, sum, cnt; 
const int dy[]={-1,0,1,0};
const int dx[] ={0,1,0,-1}; 
vector<pair<int,int>>v;
void dfs(int y,int x,vector<pair<int,int>> &v){ 
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n || visited[ny][nx])continue;
        if(abs(a[ny][nx]- a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
            visited[ny][nx] =1;
            v.push_back({ny,nx}); // 인구이동 시켜야 할 좌표들 담음
            sum += a[ny][nx]; // 인구수 
            dfs(ny,nx,v);
        }
    }
}

int main(){ 
    cin>>n>>l>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    while(true){ // 더이상 인구이동이 일어나지 않을 때까지 반복 => 무한루프 필요
        // 테스트 케이스마다 초기화하기 !
        bool flag =0; // 인구이동 발생여부 체크
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        // 2차원 배열의 모든 정점에 대해 dfs돌려서 connected component 파악
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){ // 해당 정점을 방문하지 않았으면 (이거 체크하는거 중요함 !)
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i,j});
                    sum = a[i][j];
                    dfs(i,j,v);
                    if(v.size() == 1) continue;  

                    // 탐색을 마친 뒤, 인구 이동 시킴
                    for(pair<int,int> b : v){ 
                        a[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                } 
            }
        }
        if(!flag) break;  
        cnt++;
    } 
    cout<< cnt << "\n";
    return 0;
}