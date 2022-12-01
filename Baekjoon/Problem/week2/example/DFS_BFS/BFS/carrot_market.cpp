// 당근마킷 문제
// 한 칸 움직일 때마다 당근 하나씩 소모됨. 최단거리로 갈 때 당근마킷까지 가는데 소모되는 당근의 개수는?
// 승원이는 육지(1)로만 갈 수 있으며 바다(0)로는 못감. 상하좌우로만 움직일 수 있음
// 입력: 맵의 세로길이(n), 가로길이(m), 현재위치(y, x), 당근마킷 위치(y, x)

// 2차원 좌표니까 인접리스트보다는 인접행렬이 나을듯
#include<bits/stdc++.h>
using namespace std; 
const int max_n = 104; 
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x, sy, sx, ey, ex;
int main(){ 
    scanf("%d %d", &n, &m); 
    cin >> sy >> sx; 
    cin >> ey >> ex;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        	cin >> a[i][j]; 
        }
    } 
    queue<pair<int, int>> q;  
    visited[sy][sx] = 1;
    q.push({sy, sx});  
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue; 
            if(visited[ny][nx]) continue; 
            visited[ny][nx] = visited[y][x] + 1; 
            q.push({ny, nx}); 
        } 
    }
    printf("%d\n", visited[ey][ex]); 
    // 최단거리 디버깅 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        	cout << visited[i][j] << ' '; 
        }
        cout << '\n';
    } 
    return 0;
}