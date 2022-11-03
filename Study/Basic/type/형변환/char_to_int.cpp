// 문자를 숫자로, 숫자를 문자로 변환하는 방법 -> 아스키코드 이용
// a부터 시작해 z까지 입력을 받는데 이를 정수 0~ 26까지 표현하고 싶다면
#include <bits/stdc++.h>
using namespace std;
int main(){
    char a = 'a';
    cout << int(a) - 97 << '\n'; 
    cout << int(a) - 'a' << '\n'; // 위에 줄과 같은 의미!
    return 0;
}