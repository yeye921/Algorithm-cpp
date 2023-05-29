// 큰돌 풀이법
// 앞으로 "짝짓기"문제 나오면 stack을 떠올려야함!!
// 올바른 괄호 문자열 판단 => 굉장히 유명한 문제 (이 로직은 외워두는게 좋음)
// 요 알고리즘 노트에 그려놓기 (스택에서 어떻게 작동하는지)
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool check(string s){
    stack<char> stk; // 각 문자열마다 새로운 스택 필요 (초기화)
    for(char c : s){
        if(c == '(') stk.push(c);
        else{
            if(!stk.empty()) stk.pop();
            else return false; // '('가 없는데 ')'가 들어오는 것을 체크
        }
    }
    return stk.empty(); // 다 돌렸는데 스택에 ( 이게 남아있는지 체크 => 맞으면 올바른 괄호 문자열이 아님
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(check(s)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}