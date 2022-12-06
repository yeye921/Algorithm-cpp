// 정 모르겠으면 디버깅하면서 해보자 !
// 맞왜틀 이유: vector로 하면 맞고 set으로 하면 틀림 => 왜..?
#include <bits/stdc++.h>
using namespace std;
#define y1 aaa
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, x1, x2, y1, y2, area;
int a[101][101], visited[101][101];
vector<int> v;
set<int> st;
void dfs(int y, int x){
    area++;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue; // ny = 행, nx = 열 (상하 뒤집어도 변함 x)
        if(a[ny][nx] == 0 && !visited[ny][nx]){
            dfs(ny, nx);
        }
    }
}
int main(){
    cin >> m >> n >> k;
    // 여기가 포인트임 !!
    for(int i = 0; i < k; i++){
        cin >> y1 >> x1 >> y2 >> x2; // 바꾼 좌표계(x,y 순서바뀜)로 입력 받음 
        // 직사각형에 해당하는 좌표들 입력받아 (1로) 색칠함 (여기가 제일 헷갈림)
        for(int y = y1; y < y2; y++){  // 범위에서 x2, y2를 포함하지 않는 이유..? 
            for(int x = x1; x < x2; x++){
                // cout << x << "," << y << "\n";
                a[x][y] = 1;
            }
        }        
    }
    // 이렇게 출력했을 때 우리가 생각한 그림이 나오면 됨 ! (디버깅)
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << a[i][j] << " ";
    //     }
    //         cout << "\n";
    // }

    // 2차원 배열 탐색하면서 dfs 진행
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 0 && !visited[i][j]){
                area = 0;
                dfs(i, j);
                // st.insert(area);
                v.push_back(area); // 한 노드에서 시작된 dfs가 끝날 때마다 해당 넓이를 저장해줘야함
            }
        }
    }
    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for(int i : v) cout << i << " ";
    // for(int i : st) cout << i << " ";
}