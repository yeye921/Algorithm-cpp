// string으로 입력받은 글자가 문자열인지 숫자인지 확인하는 로직
// atoi(문자열.c_str()): 문자라면 0 반환, 숫자라면 그 숫자를 반환
// c_str(): string -> char, atoi(): char -> int
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s = "89";
    string s2 = "amumu";
    cout << atoi(s.c_str()) << "\n";
    cout << atoi(s2.c_str()) << "\n";
    return 0;
}
/*
1
0
1
*/