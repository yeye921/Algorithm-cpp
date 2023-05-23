// 이동하려는 방에 적힌 숫자가 현재 방에 적힌 숫자보다 1커야 한다
// 처음 어떤 수가 적힌 방에 있어야 가장 많은 개수의 방을 이동할 수 있는지 구해라

// 처음 출발해야 하는 방 번호, 최대 몇개의 방을 이동할 수 있는지
// 이동할 수 있는 방의 개수가 최대인 방이 여럿이라면 그 중에서 가장 작은 수를 출력

// m1) dfs 완탐 + 문어박사 
// key pont!) 3에서 시작하면 3->4->5, 그렇다면 4(4->5)는 방문할 필요없음
// => 그렇기 때문에 visited 배열을 이용해서 시간 줄일 수 있음
#include <iostream>
using namespace std;
int T;
int n;
int start, temp;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int arr[1004][1004];
int visited[1004][1004]; // 방문하는 방 개수를 세려면 필요함
int dfs(int y, int x){
    int ret = 1; // 현재 방도 방개수에 포함함
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(!visited[ny][nx] && abs(arr[ny][nx] - arr[y][x]) == 1){ // 이전에 방문하지 않았고, 현재 방에 적힌 숫자보다 1커야 방문함
            if(temp > arr[ny][nx]) temp = arr[ny][nx]; // 탐색 경로 내에서 시작점 찾기!(최소값 업데이트)
            ret += dfs(ny, nx);
        }
    }
    return ret;
}
int main(){
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int ret = 0;
        fill(&arr[0][0], &arr[0][0] + 1004*1004, 0);
        fill(&visited[0][0], &visited[0][0] + 1004*1004, 0);
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        // 완탐: 2차원 모든 좌표에 대해서 dfs 돌리기
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]) continue; // 이미 방문했으면 건너뜀
                temp = arr[i][j]; // temp: 한 dfs 탐색에서 가장 최솟값 업데이트 (즉, 문제에서의 시작점)
                int cnt = dfs(i, j); // 해당 정점에서 출발할 경우, 방문하는 방 개수를 반환

                if(ret < cnt){ // 방 개수가 더 크면, start & ret 갱신
                    start = temp;
                    ret = cnt;
                }
                else if(ret == cnt && (start > temp)) start = temp; // 최대 방 개수가 여러개면 적힌수가 가장 적은 것 선택
            }
        }
        // 처음에 출발해야하는 방 번호와 최대 방 이동개수를 모두 출력해야함
        cout << "#" << tc << " " << start << " " << ret << "\n";
    }
}