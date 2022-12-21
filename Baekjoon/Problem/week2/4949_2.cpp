// stack탐색하면서 출력하는 방법 찾아보기: 스택이 빌때까지 stk.top()으로 출력하고 stk.pop()하는 방식 사용
#include <bits/stdc++.h>
using namespace std;
string s;
bool check;
int main(){
    while(true){
        getline(cin, s);
        if(s == ".") break;

        stack<int> stk;
        check = true;
        for(char c : s){
            if(c == ')'){
                if(stk.size() && stk.top() == '(') stk.pop();
                else{
                    check = false;
                    break;
                }
            }
            if(c == ']'){
                if(stk.size() && stk.top() == '[') stk.pop();
                else{
                    check = false;
                    break;
                }
            }
            if(c == '(') stk.push(c);
            if(c == '[') stk.push(c);
        }
        if(!stk.size() && check) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}