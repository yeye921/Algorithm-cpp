// 플루드필 알고리즘

// 주난이의 파동은 상하좌우 4방향으로 친구들을 쓰러뜨릴 때가지 계속해서 퍼져나간다
// 즉, 한 번의 점프는 한 겹의 친구들을 쓰러뜨린다

// 목표: 주난이가 초코바를 찾을 때까지의 최소 점프 횟수
#include <bits/stdc++.h>
using namespace std;
#define y1 aaa
const int INF = 987654321;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
string s;
int n, m, x1, y1, x2, y2, ret=INF, y, x;
bool visited[300][300];
char _map[300][300];
int main(){
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2; // 여기서 실수 !! (문제에서 x1,y1이라고 주어지는 것이 내 입장에서는 y1, x1일 수 있음 !! 항상 체크)
    x1--; y1--; x2--; y2--; // 내 좌표로 맞춰줌
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            _map[i][j] = s[j];
        }
    }
    queue<pair<int, int>> q;
    // 주난이의 위치가 시작 지점
    visited[y1][x1] = 1;
    q.push({y1, x1});

    int cnt = 0;
    // 최종 종료조건: 주난이가 초코바를 만남
    while(!visited[y2][x2]){ // 종료조건으로 여러 코드가 들어갈 수 있음 (ex. _map[ny][nx]!=0)
        cnt++;
        queue<pair<int, int>> temp;
        while(q.size()){
            tie(y, x) = q.front();
            q.pop();
        
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = 1;
                if(_map[ny][nx] == '0'){
                    q.push({ny, nx});
                }
                else {
                    _map[ny][nx] = '0';
                    temp.push({ny, nx});
                }
            }
        }
        q = temp;
    }
    cout << cnt << "\n";
    return 0;
}