// printf의 정수형, 실수형 출력
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double a = 1.23456789;
int b = 2;
int main(){
    printf("%.6lf\n", a); // 소수점 6자리까지 출력 & 반올림 (double -> lf, long long -> ld)
    printf("%2d\n", b);  // 빈칸이 2자리라는 의미
    printf("%02d\n", b); // 빈칸이 2자리인데 앞에 0붙임 ex. 07
}

