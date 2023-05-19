// 번호 문자열에서 같은 번호로 붙어있는 쌍들을 소거하고 남은 번호를 비밀번호로 만든다
// 번호 쌍이 소거되고 소거된 번호 쌍의 좌우 번호가 같은 번호면 또 소거할 수 있다
// m1) stack 이용
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n;
string s;
stack<int> st;
int main(){
    for(int tc = 1; tc <= 10; tc++){
        cin >> n >> s;
        for(int i = 0; i < n; i++){ // 문자열의 문자 탐색
            int now = s[i] - '0';
            if(st.size() && st.top() == now){ // 스택의 탑에 동일한 번호가 존재하면 제거
                st.pop();
            }
            else st.push(now);
        }
        cout << "#" << tc << " ";
        string ret;

        // 스택에 있는 숫자들을 문자열로 합침
        while(st.size()){
            ret += to_string(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end()); // 순서를 뒤집어줘야함
        cout << ret << "\n";
    }
}