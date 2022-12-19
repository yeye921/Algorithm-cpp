// 문자열들이 주어졌을 때 괄호들의 균형이 잘 맞춰져 있는지 판단하는 프로그램 짜기

// 균형 조건
// 1. 소괄호는 소괄호끼리, 대괄호는 대괄호끼리
// 2. 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다

// 하나 또는 여러줄에 걸쳐서 문자열이 주어진다. 각 줄은 마침표로 끝난다
// 입력의 종료조건으로 마지막에 점하나가 들어온다

// 힌트가 없었으면 틀렸을 것 같은 문제 !! (즉, 괄호가 하나도 없는 경우도 균형잡힌 문자열이다)
// 항상 히든케이스 생각해야함!!
// 어찌보면 당연한거 "."을 check함수 돌렸을 때 stk은 비어있을테니까

// cin은 공백을 기준으로 입력받음
// 공백을 포함해서 입력받을 때는 getline을 이용해야함!!
#include <bits/stdc++.h>
using namespace std;
string s;
string check(string s){
    stack<char> stk;
    for(char c : s){
        if(c == '[' || c == ']' || c == '(' || c == ')'){
            cout << c << " ";
            if(stk.size() && ((stk.top() == '[' && c == ']') || (stk.top() == '(' && c == ')'))){ // 괄호 중요!!
                stk.pop();
                continue; // 이게 꼭 필요한가?
            }
            else stk.push(c);
        }
    }
    if(stk.size()) return "no";
    else return "yes";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while(1){
        string s;
        getline(cin, s);
        if(s == ".") break;
        cout << check(s) << "\n";
    }
    return 0;
}