// 큰돌 풀이법
// "짝짓기" 문제 => stack 생각하기!

// (, [, ], ) 문자에 초점을 두고 생각
// '('가 들어오면 push, ')'가 들어오면 pop인 이전 로직 유지하되
// But, (] 이렇게 들어오면 안된다는 로직이 필요
#include <bits/stdc++.h> 
using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        string s; 
        getline(cin, s); // 띄어쓰기를 포함한 문자열을 입력받기 위해 사용 
        if(s == ".") break;

        stack<int> stk; // 문자로 들어와도 아스키코드로 들어가게 int로 정의함
        bool check = true; // 중간중간에 체크하는 변수 (이걸 기준으로 균형잡혔는지/아닌지 판단)

        // 각 요소들을 탐색
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){ // 닫는 소괄호가 들어옴
                if(stk.size() == 0 || stk.top() == '['){ // 아무것도 없거나 '['가 있을 경우
                    check = false; 
                    break; // 이미 중간에 틀렸으니까 탈출
                }else{
                    stk.pop();
                }
            }                                                                                                                                      
            if(s[i] == ']'){ // 닫는 대괄호가 들어옴
                if(stk.size() == 0 || stk.top() == '('){ // 아무것도 없거나 '('가 있을 경우
                    check = false; 
                    break; 
                }else{
                    stk.pop();
                }
            }
            // stack에 무조건 push하는 경우들 (여는 소/대괄호)
            if(s[i] == '(') stk.push(s[i]);
            if(s[i] == '[') stk.push(s[i]); 
        }  
        if(check && stk.size() == 0)  cout << "yes\n"; // 중간에 틀린적이 없고 스택에 아무것도 없을 경우
        else cout << "no\n";
    } 
    return 0;
} 