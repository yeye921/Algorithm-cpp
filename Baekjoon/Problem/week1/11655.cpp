// 모르겠는 것
// 영문자인지 확인하는 법 => isalpha(..)
// 개행문자까지 입력 받기 => getline(cin, s)
// 대소문자 확인하는 법 (아스키코드 말고..?)
#include <bits/stdc++.h>
using namespace std;
string s;
void ROT13(int i){ // 이 변환하는 로직 생각해는게 포인트!
    int n = (int)s[i];
    if(n > 96){ // 소문자이면
        n -= 97;
        n += 13;
        if(n > 25) n %= 26;
        n += 97; 
    } else { // 대문자이면
        n -= 65;
        n += 13;
        if(n > 25) n %= 26;
        n += 65;
    }
    s[i] = (char)n;
}
int main(){
    getline(cin, s);

    // 영문자인 것만 찾아서 변환함 (나머지는 그대로)
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])){ // 영문자이면
            ROT13(i);
        }
    }

    for(int i = 0; i < s.size(); i++) cout << s[i];
    
    return 0;
}