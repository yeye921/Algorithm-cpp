// 문자열 거꾸로 읽기 = 문자열 뒤집기 => reverse(first, last)
#include <bits/stdc++.h>
using namespace std;
string s, s2;
int main(){
    cin >> s;
    s2 = s;

    reverse(s.begin(), s.end());

    if(s == s2) cout << 1;
    else cout << 0;

    return 0;

}