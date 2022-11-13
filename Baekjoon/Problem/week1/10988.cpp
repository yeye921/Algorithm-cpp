// 문자열 거꾸로 읽기 = 문자열 뒤집기 => reverse(first, last)
#include <bits/stdc++.h>
using namespace std;
string s, temp;
int main(){
    cin >> s;
    temp = s;

    reverse(s.begin(), s.end());

    if(temp == s) cout << 1 << "\n";
    else cout << 0 << "\n";

    return 0;
}