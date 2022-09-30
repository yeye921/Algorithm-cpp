// 문자열 출력에는 보통 cout 사용
// cout의 실수형 출력
/* 
cout << fixed 를 추가하면 소수점 이하의 자릿수만 다룰 수 있게 된다.
소수점 이하의 n 개의 수를 나타낼 것이란 말이다. 
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double a = 12.3456789;
int main(){
    cout << a << '\n';
    // cout << fixed;   fixed를 추가하면 소수점 이하의 자릿수만 다룰 수 있다. 
    cout.precision(7); // cout을 사용해 정수+소수부분까지 7자리 출력 & 반올림
    cout << a << "\n";
    return 0;
}