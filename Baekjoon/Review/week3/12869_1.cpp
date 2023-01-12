// 목표: 최단거리 배열을 이용해 (0, 0, 0)까지 가는데 걸리는 최단시간 구하기
#include <bits/stdc++.h>
using namespace std;
int n;
int scv[3], visited[64][64][64];
int power[6][3] = {
    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1},
    {9, 1, 3},
    {9, 3, 1}
};
queue<tuple<int, int, int>> q;
void bfs(int a, int b, int c){
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while(q.size()){
        tie(a, b, c) = q.front();
        cout << a << " " << b << " " << c << "\n";
        q.pop();
        // 종료 조건
        if(a == 0 && b == 0 && c == 0){
            break;
        }
        for(int i = 0; i < 6; i++){
            int na = max(0, a - power[i][0]);
            int nb = max(0, b - power[i][1]);
            int nc = max(0, c - power[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> scv[i];
    }
    bfs(scv[0], scv[1], scv[2]);
    cout << visited[0][0][0] - 1 << "\n";
}