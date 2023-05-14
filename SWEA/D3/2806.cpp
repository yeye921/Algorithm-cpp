// N-Queen: DFS에서 불필요한 연산을 백트래킹을 이용해서 줄여주는 대표적인 문제
// N*N에서 N개의 퀸이 서로 공격하지 못하게 놓는 경우의 수 구하기
// m1) 루프 돌려서 체크하는 방식 => n이 10이 넘어가면 급격하게 비효율적임

// 규칙 (행, 열, 대각선)
// 1. 하나의 행에서 하나의 퀸이 나와야 한다  
// 2. 열에 대해서 경로가 겹치는지 체크해야함 => hash set을 이용하면 O(1) 대각선도 동일함
// 3-1. 하나의 좌측 대각선 안에서 x와 y간의 차이는 같다
// 3-2. 하나의 우측 대각선 안에서 x와 y간의 합은 같다

// m2)풀이
// n행으로 진행하면 성공한 것이다, ret += 1 (n번 행이면 종료=성공한다)
// j열에 퀸을 놓으면 v1[j] = 1 처리를 한다. (=열은 v1을 통해 체크함)
// 우측 대각선은 i+j가 다 같은값이므로 v2[i+j] = 1 처리를 한다. (=우측 대각선은 v2를 통해 체크함)
// 좌측 대각선은 i-j가 다 같은값이므로 v3[i-j] = 1 처리를 한다. (=좌측 대각선은 v3를 통해 체크함)
#include <iostream>
using namespace std;
int T;
int n;
#define max_n 10
int v1[max_n]; // 최대 n개
int v2[max_n*2-1]; // n*n행렬에서 좌측 대각선 개수는 모두 n*2-1개이다 (중요!)
int v3[max_n*2-1]; // n*n행렬에서 우측 대각선 개수는 모두 n*2-1개이다 (중요!)
int ret = 0;
void dfs(int row){
    if(row == n){
        ret += 1;
        return;
    }
    for(int col = 0; col < n; col++){
        // 3가지 조건을 모두 만족해야지 dfs를 진행함
        if(v1[col] == 0 && v2[row+col] == 0 && v3[row-col] == 0){
            v1[col] = 1;
            v2[row+col] = 1;
            v3[row-col] = 1;

            dfs(row + 1); // 완탐 진행

            v1[col] = 0; // 완탐 해제
            v2[row+col] = 0;
            v3[row-col] = 0; 
        }
    }
}
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        fill(v1, v1 + max_n, 0);
        fill(v2, v2 + max_n*2-1, 0);
        fill(v3, v3 + max_n*2-1, 0);
        ret = 0;

        cin >> n;
        dfs(0);
        cout << "#" << test_case << " " << ret << "\n";
    }
}
