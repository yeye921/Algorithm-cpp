// 이걸 어떻게 플어야 할까라는 생각하면안됨
// 항상 문제를 처음 보면 해야하는 생각 => 1. 무식하게 풀수있는지 생각, 2. 적용할 수 있는 알고리즘이 있는지 생각 

// 이 문제는 무식하게 풀 수 있는 문제
// N이 10000일때 값은 대략 6660000(666만)이다
// 문제마다 다르지만 보통 1000만이하이면 무식하게 풀 수 있으니 이 방법 먼저 생각하기 !

// i를 증가시키면서 666을 포함하고 있는지 체크하는게 핵심 !!
#include<bits/stdc++.h>
using namespace std; 
int n; 
int main() {
    cin >> n; 
    int i = 666; // 시작조건 정의
    for(;; i++){ // for(시작조건; 끝조건; 증감조건) 끝조건이 없으므로 무한루프를 의미
        if(to_string(i).find("666") != string::npos){
            n--; // 666이 포함되어 있으면 n감소
            // cout << n << ":" << i << "\n"; 
        }
        if(n == 0)break;
    }
    cout << i << "\n"; 
}