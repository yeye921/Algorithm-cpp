// 아스키코드에 +13하면 되는 문제임
// 방법1) 경험적으로 해서 식 세우기 Z=90 -> ROT13 -> M=77 (즉, 90 + 13 => 77이 되어야 함) (-26처리가 필요)
// 방법2) 좌표이동 해서 하기
// 암기: A = 65, a = 97
// 영문자인지 확인하는 법 => isalpha(..)
// 개행문자까지 입력 받기 => getline(cin, s)
#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    getline(cin, s);

    // 입력으로 대문자, 소문자, 공백, 숫자만 들어옴 (영문자만 변환)
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 65 && s[i] <= 90){ // 대문자인 경우
            if(s[i] + 13 > 90) s[i] = s[i] + 13 - 26; // 범위 밖으로 나가면 좌표이동 처리해줘야 함
            else s[i] = s[i] + 13;
        }
        else if(s[i] >= 97 && s[i] <= 122){ // 소문자인 경우
            if(s[i] + 13 > 122) s[i] = s[i] + 13 -26; // 범위 밖으로 나가면 좌표이동 처리해줘야 함
            else s[i] = s[i] + 13;
        }
        cout << s[i];
    }
    return 0;
}