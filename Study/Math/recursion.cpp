// 재귀 함수 : 정의 단계에서 자신을 재참조하는 함수
// 큰 문제를 작은 부분문제로 나눠서 풀 때 사용한다

// 주의사항
// 반드시 기저사례를 써야한다 (종료조건)
// 싸이클이 있다면 쓰면 안된다
// 반복문으로 될 것 같으면 반복문으로 (함수 호출에 대한 비용)

// 예시
// 팩토리얼: f(n) = n * f(n-1)     ex. 6! = 6*5*4*3*2*1
// 피보나치: f(n) = f(n-1) + f(n-2) ex. 0, 1, 1, 2, 3, 5, 8, 13, 21, ..

#include <bits/stdc++.h>
using namespace std;
// 1. 팩토리얼을 재귀로 구현
int fact(int n){
    if(n == 0 || n == 1) return 1;  // 종료조건: 0! = 1! = 1
    return n * fact(n - 1);
}
// 2. 팩토리얼을 반복문으로 구현 (추천)
int fact1(int n){
    int ret = 1;
    for(int i = 1; i <= n; i++){
        ret *= i;
    }
    return ret;
}
// 피보나치는 반복문으로 구현하면 복잡, 재귀로 하자
int fibo(int n){
    if(n == 1 || n == 0) return n;  // 종료조건: f(0)=0, f(1)=1
    return fibo(n - 1) + fibo(n - 2);
}
int n = 5;
int main(){
    cout << fact(n) << " " << fibo(n) << "\n";
    return 0;
}