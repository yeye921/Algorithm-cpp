// 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열이라고 부른다
// 주어진 괄호 문자열이 vps인지 아닌지를 판단
// 이 문제는 스택 문자열 폭발? 문제!

// 문자를 문자열로 변환하는 방법: string(int size, char c);
#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        stack<string> stk; // 테스트 케이스 문제 => 초기화 중요
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            // 여기에 알고리즘 들어감
            // 지금 넣으려는 것과 스택의 제일 위에 있는거랑 비교
            // stk.top을 할때는 항상 스택의 사이즈 체크해야함!
            if(stk.size() && (stk.top() + s[i] == "()")){ 
                stk.pop();
                continue;
            }
            else stk.push(string(1, s[i])); // 문자열을 자르면 문자니까 다시 문자열로 변환하는 과정 필요!
        }
        // 다 처리하고 나서 스택의 사이즈 체크
        if(!stk.size()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}