#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;

    for(char c : s){
        if(c == '(') stk.push(c); // '('는 무조건 넣기
        else {
            if(stk.size()) stk.pop(); // 스택에 뭔가 존재할 경우 => pop!
            else return false;
        }
    }
    if(stk.empty()) answer = true;
    else answer = false;
    return answer;
}