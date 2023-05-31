// 문자열 S가 "pi", "ka", "chu"를 이어 붙여서 만들 수 있으면 "YES"를 아니면 "NO"를 출력한다.
// 스택말고는 다른 방법이 생각이 안남.. 

// 내 풀이 (스택과 유사한 방식 이용)
// 1. 입력받은 문자열을 순회하면서 stk문자열에 쌓고, pi, ka, chu와 일치하는지 확인
// 2. 일치하면 stk을 비우고 일치하지 않으면 계속 더함
// 3. 최종적으로 스택이 비면 YES 아니면 NO를 반환함
#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin >> s;
    string stk;
    for(char c : s){ 
        stk += c;
        if(stk == "pi" || stk == "ka" || stk == "chu"){
            stk = "";
        }
    }
    // 순회가 끝나면 체크
    if(!stk.length()) cout << "YES\n";
    else cout << "NO\n";
}