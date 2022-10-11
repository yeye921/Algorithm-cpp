// 가장 마지막으로 들어간 데이터가 가장 첫번째로 나오는 성질을 가진 자료구조
// LIFO(Last In First Out, 재귀적인 함수, 알고리즘에 사용됨 (ex. 웹 브라우저 방문기록)
// 삽입, 삭제에 O(1), 탐색에 O(n)이 걸림
// 삽입, 삭제가 top(맨 위)에서만 일어남
// "교차하지 않고"라는 문장이 나오면 스택을 사용할지 말지 의심해봐야 함

#include <bits/stdc++.h>
using namespace std;
stack<string> stk;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    stk.push("엄");
    stk.push("준");
    stk.push("식");
    stk.push("화");
    stk.push("이");
    stk.push("팅");

    while(stk.size()){
        cout << stk.top() << "\n";
        stk.pop();
    }
}