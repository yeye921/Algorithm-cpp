// 소수판별법 - 효율적인 방법
#include <bits/stdc++.h>
using namespace std;
bool isPrimeNumber(int x){
    int end = (int) sqrt(x);
    for(int i = 2; i <= end; i++){
        if(x % i == 0) return false;
    }
    return true;
}

// 에라토스테네스의 체
// 1. 나동빈 방식 
// for문에서 int로 선언하는거 까먹지 말기!!
void eratos(){
    int max_n = 10;
    int a[11];
    // 초기화
    for(int i = 2; i <= max_n; i++){
        a[i] = i;
    }
    // 특정 수의 배수들을 모두 지움 (이미 지운 수는 건너뜀, 자기자신은 제외)
    for(int i = 2; i <= max_n; i++){
        if(a[i] == 0) continue;
        for(int j = 2 * i; j <= max_n; j += i){
            a[j] = 0;
        }
    }
    // 2부터 남은 수 출력
    for(int i = 2; i <= max_n; i++){
        if(a[i] != 0) cout << a[i] << "는 소수이다\n";
    }
}

// 2. 큰돌 방식 - 배열의 크기가 일정 수준 이상일 뗴
bool check(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
int main(){
    cout << isPrimeNumber(7) << "\n";
    // eratos();

    for(int i = 1; i <= 20; i++){ // 1~20의 수를 소수 판별
        if(check(i) != 0){
            cout << i << "는 소수입니다.\n";
        }
    }
    return 0;
}
