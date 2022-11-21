// tip)
// 문제 또는 예시를 봤을 때 이해가 안가면 => 도식화(그림으로 그릴 생각) 하기!
// 즉, 뒤집거나 하나 더 붙여보가나 90도 회전해보거나
// 문제에서 짝짓기 OR 폭발이 있으면 => stack을 사용해볼까라고 생각하기 !!

// stk.top()을 참조할 때 항상 스택에 값이 있는가를 (stk.size()로) 체크해야함
// => 자료구조를 없는데 참조하려고 하면 참조 에러가 발생함

// 문제 해설
// 이 문제에서는 문자열을 90도 회전해본 게 맘에 듬
// !! 가장 뒷부분과 그 앞부분이 같은지 비교해서 같으면 pop처리를 반복했을 때, 그 컨테이너의 사이즈가 0이면 좋은 단어
// 따라서 가장 뒷 부분을 참조하기 쉬운 자료구조인 stack을 사용할 것임
#include <bits/stdc++.h>
using namespace std;
int n, ret;
string s;
int main(){
    ios_base:sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        stack<char> stk; // 문자열을 받을 때 마다 스택을 초기화 해줘야 함 (ex. test case)

        // 포인트 !!
        // 다 때려넣은 다음에 탐색하면서 체크하는게 아니라
        // 넣는 시점에 체크함
        for(char c : s){
            if(stk.size() && stk.top() == c) stk.pop();
            else stk.push(c);
        }
        if(stk.size() == 0) ret++;
    }
    cout << ret << "\n";
}