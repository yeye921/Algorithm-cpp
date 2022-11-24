// 문제를 볼 때 최대/최소 범위를 가장 먼저 봐야함!

// 두가지 개념이 사용됨
// 1. (곱한 것을 어떤 변수에 집어넣는걸 기반으로) 반씩 나누면서 재귀함수를 구현 => 분할정복 문제
// 2. 모듈러 연산 개념 (값이 오버플로나는 것을 막기위해)

// ex) go(10, 12) % c = (go(10, 6) * go(10, 6)) % c 
//                    = (ret * ret) % c               <= 이걸 이해하는 게 중요!
// +) 그리고 ret은 이미 모듈러 연산이 적용되어 있는 값(b == 1일 경우 a % c)이기 때문에 다시 모듈러 연산을 할 필요가 없음!
#include<iostream> 
using namespace std;
typedef long long ll;
ll a, b, c;
ll go(ll a, ll b){
    if(b == 1) return a % c; // !! 재귀함수의 필수조건 = 기저사례
    ll ret = go(a, b / 2);          // 반씩 나눈다음 변수에 담아둠
    ret = (ret * ret) % c;          // 담아둔 변수를 이용해 곱한다음 모듈러 연산해줌                
	if(b % 2) ret = (ret * a) % c;  // !! b가 홀수라면, 마지막에 한 번 더 곱해줘야 함  
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
    cout << go(a, b) << "\n";
    return 0;
}
