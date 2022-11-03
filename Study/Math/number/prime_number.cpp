// 소수를 판별하는 법
// 소수: 1과 자신만을 약수로 갖는 수
#include <bits/stdc++.h>
using namespace std;

// 1. 시간복잡도 O(N): 모든 경우의 수를 다 돌며 약수여부를 확인함, 비효율적 
bool isPrimeNumber(int x){
    for(int i = 2; i < x; i++){ // 2부터 (특정한수보다 1작은수, x-1)까지 확인하면서 한번이라도 약수가 발견되면 소수가 아님!
        if(x % i == 0) return false; // 나누어 떨어진다는 것은 그 수를 약수로 갖는다는 의미
    }
    return true;
}

// 2. 시간복잡도 O(N^(1/2)): 특정한 숫자의 제곱근까지만 약수의 여부를 검증함, 효율적
// 제곱근을 구하는 라이브러리 이용 -> math.h
bool isPrimeNumber2(int x){
    int end = (int) sqrt(x); //end는 x의 제곱근
    for(int i = 2; i <= end; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    cout << isPrimeNumber(97) << "\n";
    cout << isPrimeNumber2(97) << "\n";
    return 0;
}