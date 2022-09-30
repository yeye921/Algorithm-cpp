// 입력받은 문자열이 문자이면 0 반환, 숫자이면 그 숫자를 반환
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s = "1";
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
