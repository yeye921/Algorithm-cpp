// 왜 틀렸징..?

// 자연수 A를 B번 곱한수를 c로 나눈 나머지
// 즉, (A * A * .......) % c

// 1. A를 B번 곱하기 => for문이 아니라, 재귀(분할정복)
// 2. 오버플로를 방지하기위해 곱연산이 진행될 때마다 모듈러 연산을 해준다 !

// 1.의 디테일: 분할한 것을 어떤 변수에 저장해두고 그것을 이용함!
#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, c, ret = 1;
ll go(ll a, ll b){
    // 기저사례
    if(b == 1) return a;
    // b가 짝수이면
    ret = go(a, b / 2);
    ret = (ret * ret) % c;
    if(b % 2){ // b가 홀수이면
        ret = (ret * a) % c;
    } 
    return ret;
}
int main(){
    ll sol;
    cin >> a >> b >> c;
    sol = go(a, b);
    sol %= c;
    cout << sol << "\n";
}