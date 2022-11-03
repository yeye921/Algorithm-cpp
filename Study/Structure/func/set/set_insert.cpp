// set: 특정 순서에 따라 고유한 요소를 저장하는 컨테이너, 중복되는 요소는 없고 오로지 unique한 값만 저장하는 자료구조
// pair나 int형을 집어넣어서 만들 수 있음
#include <bits/stdc++.h>
using namespace std;
int main(){
    set<pair<string, int>> st;
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 2});
    cout << st.size() << "\n"; // 중복된 요소는 제거함
    for(auto it : st) cout << it.first << " : " << it.second << "\n";

    set<int> st2;
    st2.insert(1);
    st2.insert(2);
    st2.insert(2);
    for(auto it : st2){
        cout << it << "\n";  // 중복된 값은 제거되며, 희소한 값만을 출력함
    }
    return 0;
}