// 문어박사 DP문제
// 이미 계산한 피보나치 수를 다시 계산하지 않고 배열에 저장해놓고 꺼내쓰는 방식
#include <bits/stdc++.h>
using namespace std;
int n;
int fibo[49];
// 이렇게 재귀함수 방식으로 하면 시간초과남!
// int func(int n){
//     if(n == 0) return 0;
//     else if(n == 1) return 1;
//     return func(n-1) + func(n-2);
// }
int main(){
    cin >> n;
    fibo[0] = 0;
    fibo[1] = 1;

    // n까지 피보나치 배열을 만들어 놓고 출력함 (bfs에서 visited로 최단거리 배열 만드는 것과 유사)
    for(int i = 2; i <= n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout << fibo[n] << "\n";
}