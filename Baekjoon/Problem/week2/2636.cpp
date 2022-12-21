// 제일 바깥부분이 0이기 때문에 비교적 쉬운 문제 (바깥이 1이면 문제 어려워짐)
// 바깥 부분부터 dfs탐색하면서 1을 발견하면 멈춰야 함 (1을 발견하면 return) (dfs가 코드가 짧기 때문에 탐색에 이걸 이용)
// => 이렇게 하다보면 치즈의 바깥부분만 visited처리되니까 이 부분만 삭제하면 치즈 녹이기 구현 가능

// 이런 문제를 처음 풀어보는 사람들이 많이하는 실수
// dfs호출(= go(0, 0))은 한번만 하면 타고타고 가서 다 탐색 완료하게 되는데 이 호출을 여러번 하는 사람들 있음
// 딱 한번만 하면 dfs가 퍼져나가게 됨

// 결론
// 1. 맨 바깥부분에서 dfs탐색하면서 1을 만나면 종료
// 2. 그렇게 만난 치즈 부분을 v에 담아서 삭제
#include <bits/stdc++.h>
using namespace std; 
int a[104][104], visited[104][104];
int dy[]={-1,0,1,0}, dx[] = {0,1,0,-1};   
int n,m,cnt,cnt2;
vector <pair<int,int>>v; // 녹아야 할 치즈들을 담을 v (여기다 담은 뒤 삭제)
void go(int y,int x){
	visited[y][x] = 1;
    // 이 부분만 다르고 나머지는 일반적인 dfs와 동일
    if(a[y][x]==1){ // 치즈를 만나면
        v.push_back({y,x}); // 녹이기 위해서 v에 담음
        return; // 종료
    }
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx])continue; 
        go(ny,nx);
    }
    return;
}


int main(){ 
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    while(true){ // 치즈가 녹는 만큼 돌려야 함 (치즈가 녹고 > 확인하고 반복) 
        // 테스트케이스는 초기화가 중요 (dfs마다 초기화)
        fill(&visited[0][0],&visited[0][0] + 104 * 104,0);
        v.clear(); 
        cnt2 =0; // 모두 녹기 한 시간 전에 남아있는 치즈조각 개수

        go(0,0); // dfs한번만 호출하면 타고타고가서 다 탐색하게 된다

        for(pair<int, int> b : v){
			cnt2++;
			a[b.first][b.second] = 0; // 치즈를 삭제한다
		}    
        bool flag = 0; // 치즈가 다 녹았나/안녹았나 체크하기 위한 변수
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] != 0) flag = 1;
            }
        }
        cnt++; // 치즈가 몇번만에 녹았는지 셈
        if(!flag) break; // 치즈가 다 녹았으면 탈출
    }
    cout<<cnt<<"\n" << cnt2 << '\n'; 
}
