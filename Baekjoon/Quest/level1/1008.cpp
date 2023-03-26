// A / B의 실제 정답과 출력값의 절대오차 또는 상대오차가 10^(-9)이하이면 정답이다

// 실수형 자료형 2가지
// float: 4byte(32bit) 자료형이다 (=단정밀도, single precision)
// double, long double: 8byte(64bit) 자료형이다 (=배정밀도, double precision)
// 오차를 줄이기 위해선 많은 비트를 사용하는 큰 자료형을 써야한다 ! (float을 쓰면 이 문제는 틀린다)

// float의 오차 범위는 10^(-7)정도고 double의 오차 범위는 10^(-15)정도이다. 
// 이 문제는 오차 범위가 10^(-9)이하여야 하기 때문에, double or long double을 사용해야 함
// 그리고 출력할 때도 출력할 소수점 자리를 9개 이상! 출력하도록 해야한다

// 만약에 float으로 하고 소수점만 9자리까지 출력하게되면 그것도 정답인가?? => 아님. 틀림!

// 출력 방법 (precision, fixed 사용)
// precision(n): 실수 "전체 자리 수" 중 n자리까지 표현 (ex. double a = 1234.5678; precision(6)=> 1234.56;)
// 정수부분은 신경쓰지 않고 소수점 아래로만 고정하고 싶으면 fixed 사용

#include <bits/stdc++.h>
using namespace std;
double a, b;
int main(){
    cin >> a >> b;
    cout.precision(9); // 전체 자리 수를 9자리로 맞춤
    cout << fixed; // 소수점 아래로만 9자리로 맞춤 !
    cout << a / b << "\n";
    return 0;
}