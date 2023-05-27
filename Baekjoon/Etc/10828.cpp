// stack의 기본 함수들 정리하기
// 시간 아주 조금 더 줄이려면 문자열의 첫글자만 확인하는 방법도 있음
#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> st;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string order;
        cin >> order;

        if(order == "push"){ 
            int x;
            cin >> x;
            st.push(x);
        } 
        else if(order == "pop"){ 
            if(st.size()){
                cout << st.top() << "\n";
                st.pop();
            } else {
                cout << "-1\n";
            }
        } 
        else if(order == "size"){
            cout << st.size() << "\n";
        } 
        else if(order == "empty"){
            if(st.empty()) cout << "1\n";
            else cout << "0\n";
        } 
        else if(order == "top"){ 
            if(st.size()) cout << st.top() << "\n";
            else cout << "-1\n";
        }
    }
}