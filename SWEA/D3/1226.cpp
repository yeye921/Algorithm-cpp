// 주어진 미로의 출발점부터 도착점까지 도달할 수 있는지(0 또는 1로) 판단하는 프로그램
// 0: 길, 1: 벽, 2: 출발점, 3: 도착점

// dfs로 풀어야할까? bfs로 플어야할까..?
// m1) dfs
#include <iostream>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int T;
bool flag;
int sy, sx, ey, ex;
const int max_n = 20;
int arr[max_n][max_n];
bool visited[max_n][max_n];
void dfs(int y, int x){
    visited[y][x] = 1;
    if(y == ey && x == ex){ // 재귀함수의 필수조건 (기저사례)
        flag = 1;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= 16 || nx >= 16) continue;
        if(arr[ny][nx] == 1 || visited[ny][nx]) continue; // 벽이거나 이미 방문했으면 건너뜀
        dfs(ny, nx);
    }
}
int main(){
    for(int tc = 1; tc <= 10; tc++){
        flag = 0;
        fill(&arr[0][0], &arr[0][0]+ max_n * max_n, 0);
        fill(&visited[0][0], &visited[0][0]+ max_n * max_n, 0);
        cin >> T;
        for(int i = 0; i < 16; i++){
            string s;
            cin >> s;
            for(int j = 0; j < 16; j++){
                arr[i][j] = s[j] - '0';
                if(arr[i][j] == 2){
                    sy = i;
                    sx = j;
                }
                else if(arr[i][j] == 3){
                    ey = i;
                    ex = j;
                }
            }
        }
        dfs(sy, sx);
        cout << "#" << T << " " << flag << "\n";
    }
}