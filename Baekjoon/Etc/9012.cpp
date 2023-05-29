// 문자열 폭발과 같은 문제. stack을 이용해서 풀면 되는 문제
// stack의 empty함수는 스택이 비어있으면 1, 비어있지 않으면 0을 반환하는 함수
// 중요) 테스트케이스 문에서 스택 초기화를 안하는 실수해서 시간 날림 => 항상 테케문은 주의해야함!
// 스택의 경우 인덱스로의 접근이 불가하다. 하나씩 pop하면서 접근해야함
#include <bits/stdc++.h>
using namespace std;
int T;
string str;
stack<char> stk;
int main(){
    cin >> T;
    for(int i = 0; i < T; i++){ // 테스트 케이스 문제
        stk = stack<char>(); // 스택을 초기화 하는법
        bool flag = 1;
        cin >> str;
        for(int j = 0; j < str.size(); j++){
            if(str[j] == '(') {
                stk.push('(');
            }
            else {
                if(stk.size()) {
                    stk.pop();
                }
                else { // 스택이 비어있는데 (가 들어오면 종료함
                    flag = 0;
                    break;
                }
            }
        }
        if(stk.empty() && flag) cout << "YES\n"; // 스택이 비어있고 중간에 문제가 없었으면 yes
        else cout << "NO\n";
    }
}