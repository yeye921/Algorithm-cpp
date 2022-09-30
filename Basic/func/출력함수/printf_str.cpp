#include <bits/stdc++.h>
using namespace std;
int a = 1;
char s = 'a';
string str = "어벤져스";
double b = 1.223123; // 실수는 6자리까지 출력되고 반올림됨
int main(){
    printf("아이엠어 아이언맨 : %d\n", a);              // printf의 정수 출력
    printf("아이엠어 아이언맨 : %c\n", s);              // printf의 문자 출력
    printf("아이엠어 아이언맨 : %s\n", str.c_str());    // printf의 문자열 출력
    printf("아이엠어 아이언맨 : %lf\n", b);             // printf의 실수 출력
}