// 스택은 자료를 넣는 입구와 자료를 뽑는 입구가 같아, 제일 나중에 들어간 자료가 제일 먼저 나온다
// 문제를 처음에 봤을 때 이해가 조금 안갔음 => 입출력 보고 이해함 (스택의 성질을 이용해야하는 문제)
// 예제들을 스택에 직접 넣었다 빼면서 규칙을 찾는게 중요함

// 0. 입력된 값까지 1부터 수를 증가시키면서 스택에 넣음
// 1. 스택의 top과 입력된 값이 같으면 pop
// 2. 수를 증가시켜도 스택의 top과 입력된 값이 다르면 NO 출력 후 종료
// +) push와 pop을 진행할 때는 나중에 따로 벡터에 담아야 함
#include <bits/stdc++.h>
using namespace std;
int n, x;
stack<int> st;
vector<char> ans;
int idx = 1;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;

        while(idx <= x){ // x가 될때까지 idx를 증가시키면서 스택에 넣음
            st.push(idx); // 스택에 넣음
            idx++;
            ans.push_back('+'); // 여기가 포인트!
        }
        if(st.top() == x){
            st.pop();
            ans.push_back('-');
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    for(int i = 0; i < ans.size(); i++){ // 스택의 마지막 숫자와 입력한 숫자가 같으면 pop
        cout << ans[i] << "\n";
    }
    cout << "\n";
    return 0;
}