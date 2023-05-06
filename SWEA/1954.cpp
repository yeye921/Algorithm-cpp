// 정수 n을 입력 받아, N크기의 달팽이 출력하기
// 힌트: dfs와 방향벡터 이용

// 규칙1) 범위 이내일때만 작업함 (범위를 벗어나면 방향이 바뀜)
// 규칙2) 배열 값이 0인 경우(값이 비어 있을때)만 작업함, 값이 이미 들어있는 경우에는 방향을 전환함
// 규칙3) 적을 값(cnt)가 n^2 이하일 때까지만 이 작업을 수행한다. 
// 방향의 종류는 4가지이고 반복/순환함 (오른쪽, 아래, 왼쪽, 위)
#include <iostream>
using namespace std;
int T, test_case;
int n;
int _map[13][13];
const int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        memset(_map, 0, sizeof(_map));
        int y = 0, x = 0;
        int cnt = 1;
        int dir = 0;
        cin >> n;
        while(cnt != n*n+1){ // 카운트가 n제곱+1이 되면 멈춤
            _map[y][x] = cnt;

            int ny = y + dy[dir % 4];
            int nx = x + dx[dir % 4];

            // 다음 지점이 범위를 벗어나거나 이미 값이 들어있으면 방향을 전환함
            if((nx < 0 || ny < 0 || nx >= n || ny >= n) || _map[ny][nx]){
                dir++;
                ny = y + dy[dir % 4];
                nx = x + dx[dir % 4];
            }
            y = ny;
            x = nx;
            cnt++;
        }
        cout << "#" << test_case << "\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << _map[i][j] << " ";
            }
            cout << "\n";
        }
    }
}