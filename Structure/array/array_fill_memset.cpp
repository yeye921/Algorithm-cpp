// 주제: vector/array 초기화: fill(), memset()이용
// fill(시작값, 끝값, 초기화하는값)
// memset(초기화할배열, 값, 배열크기)
#include <bits/stdc++.h>
using namespace std;
int main(){
// 정리1. vector 초기화
    vector<int> v[10];   // 벡터 v를 10개 생성함
    vector<int> v(n, 0); // n개의 벡터 생성 & 값을 모두 0으로 초기화
    
    // vector로 2차원 배열 매트릭스 만들기 (vector_2D_init.cpp참고)
    vector<vector <int>> checked;
    // n+1 크기의 2차원벡터를 n+1크기의 벡터(0으로초기화됨)로 채움 
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0)); // 즉, (n+1)*(n+1)벡터를 0으로 초기화

    fill(v.begin(), v.end(), 0);  // fill을 이용한 2차원 벡터초기화


// 정리2. array 초기화
    memset(checked, 0, sizeof(checked)); // memset을 이용한 초기화

    // 배열초기화 방법2 (편법): 전체 0으로 초기화. 일부 컴파일러에서 통하지 않을 수 있음
    int dp[10] = {0,};
    int dp[10][10] = {{0, } }; // 2차원 배열 초기화
    fill(dist, dist + MAX_N, 0); // fill을 이용한 2차원 벡터초기화1 (야매)

    // 부분초기화: 0번째를 0, 1번째를 1로 초기화 함
    int a[n] = {0, 1};

    // fill을 사용한 2차원 배열 초기화2
    for(int i = 0; i < 10; i++) fill(dp[i], dp[i]+10, 0);
    fill(&arr[0][0], &arr[0][0] + n*m, k); // 이런식으로 한번에 초기화도 가능
}