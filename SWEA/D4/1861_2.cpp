/*
BFS를 이용한 문어박사 풀이
핵심1) 3에서 시작하면 3->4->5, 그렇다면 4(4->5)는 방문할 필요없음
=> 이게 되는 이유는 1차이 나는 것끼리 연결되어 있기 때문이다 (이해 안가면 그려봐라)

9 3 4
8 1 5
7 6 2
위 행렬을 2차원 탐색을 진행할 경우, 3->4->5, 8->7->6이 나올 수 있으므로, 
현재 수의 +1뿐만아니라 -1이어도 이동 가능하게 해야함!

핵심2) ans 배열을 이용해서 한 bfs를 돌면서 방의 숫자를 집어넣음
=> 이 배열을 통해 출발점(방의 숫자 중 최소값)과 최대 방 개수를 동시에 구할 수 있음
==> 출발점: ans 배열의 최솟값, 최대 방 개수: ans 배열의 길이를 구해서 최대값 갱신해나감
*/
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define max_n 1004
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int T;
int n;
int arr[max_n][max_n];
int visited[max_n][max_n];
// 두가지 값을 반환하는 함수
pair<int, int> bfs(int y, int x){
    vector<int> ans;  // 한번의 bfs탐색에서 방문하는 방의 숫자를 기록하는 배열
    queue<pair<int, int>> q;

    q.push({y, x});
    visited[y][x] = 1;
    ans.push_back(arr[y][x]);
    while(q.size()){
        int a, b; // y,x 대신에 a,b 썼으면 아래도 통일하기
        tie(a, b) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = a + dy[i];
            int nx = b + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(!visited[ny][nx] && abs(arr[ny][nx] - arr[a][b]) == 1){
                q.push({ny, nx});
                visited[ny][nx] = 1;
                ans.push_back(arr[ny][nx]);
            }
        }
    }
    // ans에서 제일 작은 번호, 개수를 리턴
    int mn = *min_element(ans.begin(), ans.end());
    int len = ans.size();
    return make_pair(mn, len);
}
int main(){
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        fill(&arr[0][0], &arr[0][0] + max_n*max_n, 0);
        fill(&visited[0][0], &visited[0][0] + max_n*max_n, 0);
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        // 1. 전체를 순회하며 방문안한 곳을 bfs 돌림
        // 2. mn(시작점)과 cnt을 반환하면서 갱신해줘야함
        int start = n*n;
        int cnt = 0; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    pair<int, int> pi = bfs(i, j);
                    // 나중에 갱신되는 temp 값들 (아래4줄 중요!)
                    int t_start = pi.first;
                    int t_cnt = pi.second;

                    // 이 부분이 실수하기 좋음!!
                    // 해당 bfs 결과의 방 개수가 더 크면 현재값이 정답이고
                    // 방 개수가 똑같으면 시작점이 작은 수로 갱신함
                    if((cnt < t_cnt) || ((cnt == t_cnt) && (start > t_start))){
                        cnt = t_cnt;
                        start = t_start;
                    }
                }
            }
        }
        cout << "#" << tc << " " << start << " " << cnt << "\n";
    }
}