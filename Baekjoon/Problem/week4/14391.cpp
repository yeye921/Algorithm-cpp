// 큰돌 풀이
// 직사각형을 조각으로 자르는 것을 어떻게 코드로 구현할거냐?가 핵심!
// => (0:가로, 1:세로)라는 약속을 정해서 맵을 0또는 1의 숫자로 채움 <= 요런 아이디어가 필요한 문제
#include <iostream>
#include <cstdio>
using namespace std;
int a[4][4], n, m, ret; 
int main() { 
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d",&a[i][j]);
        }
    } 
    // 이진수로 모든 경우의 수를 나타냄 => 비트마스킹!
    for (int s = 0; s < (1 << (n * m)); s++) { // ex. s = 000100010 
        // 0을 체크하는 로직 (= 가로 조각들의 합을 구하는 로직)
        int sum = 0;
        for (int i = 0; i < n; i++) { // 세로줄
            int cur = 0; // 한 행마다 조각들 계산
            for (int j = 0; j < m; j++) { // 가로줄
                int k = i * m + j; // k는 s의 해당 원소를 접근하는 idx의 용도 (이 부분이 좀 헷갈림!) (중요!)
                if ((s & (1<<k)) == 0) { // 0이면 가로(왼>오)로 수 이어붙임
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur; // 이어붙인 수를 전체 sum에 더해줌
                    cur = 0; // 초기화
                }
            }
            sum += cur;
        }
        // 1을 체크하는 로직 (= 세로 조각들의 합을 구하는 로직)
        // 원래는 행기준 탐색(ex. i>j)을 하지만 여기서는 (세로로 탐색하기위해) 열기준 탐색을 함! (ex. j>i) (중요!)
        for (int j = 0; j < m; j++) {
            int cur = 0; // 한 열마다 조각들 계산
            for (int i = 0; i < n; i++) {
                int k = i * m + j;
                if ((s & (1<<k)) != 0) { // 1이면 세로(위>아래)로 수 이어붙임
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ret = max(ret,sum); // 경우의 수 마다 최대값 갱신
    }
    cout << ret << '\n';
    return 0;
}