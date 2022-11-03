// 에라토스테네스의 체
// 배열의 크기가 일정 수준(1000민 이상)을 벗어나면 방법 2를 사용해야 함
#include <bits/stdc++.h>
using namespace std;

// 방법 1. 배열의 크기가 작을 때 (이 방식은 나중에 꼭 숙지하자)
vector<int> era(int max_n){
    vector<int> v;
    for(int i = 2; i <= max_n; i++){
        if(che[i]) continue;                  // 이미 초기화 된 것들은 건너뜀
        for(int j = 2*i; j <= max_n; j += i){ // 특정한 수의 배수들을 1로 초기화 (자기자신 제외 ex.2)
            che[j] = 1;
        }
    }
    for(int i = 2; i <= max_n; i++) if(che[i] == 0) v.push_back(i); // 1로 초기화되지 않은 것들만 v에 담음
    return v;
} 

// 방법 2. 배열의 크기가 일정수준 이상일 때 -> 일일히 소수를 판별하는 bool 함수를 만들어줘야 함
bool check(int n){
    // 아래 두 줄은 for 예외처리..?
    if(n <= 1) return 0;
    if(n == 2) return 1;

    if(n % 2 == 0) return 0;

    // 제곱근 방식 이용
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
int main(){
    for(int i = 1; i <= 20; i++){
        if(check(i)){
            cout << i << "는 소수입니다.\n";
        }
    }
    return 0;
}