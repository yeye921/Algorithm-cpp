// 사실상 내 풀이랑 완전 똑같음! 그냥 개념만 참고!
// 완전탐색으로 풀면 시간 오래걸림 => 최적해를 찾는 방법 DP를 이용할 것임

// dp 풀이과정
// 1. 시각적으로 접근해서 규칙성(반복되는 부분)을 찾는것
// 2. dp[] table 과 dp[i] 정의 (점화식)
// 3. 초기값 설정, 테이블을 채우는 반복처리를 진행

// dp[i]: i번째의 피보나치 수
#include <bits/stdc++.h>
using namespace std;
int n;
int dp[48]; // dp 테이블 정의 (범위: n까지)
int main(){
    cin >> n;

    // dp 초기값 설정
    dp[0] = 0;
    dp[1] = 1;

    // 반복해서 처리하며 테이블 채움
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << "\n";
    return 0;
}