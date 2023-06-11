// m1) set을 이용해 중복원소를 제거하고 size를 출력하는 방법
// m2) 벡터의 중복원소 제거하는 방법(sort > erase > unique 함수) 이용하기

// set 자료구조(중복된 값은 제거되며, map과 같이 자동 정렬된다)
// 주요함수: insert, erase, find, size
#include <bits/stdc++.h>
using namespace std;
int n;
set<int> st;
int main(){
    for(int i = 0; i < 10; i++){
        cin >> n;
        st.insert(n % 42);
    }
    cout << st.size() << "\n";
}

// m2)
// vector<int> v;
// int main(){
//     for(int i = 0; i < 10; i++){
//         cin >> n;
//         v.push_back(n % 42);
//     }
//     // sort > erase > unique의 순서를 지켜줘야함
//     sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());
//     cout << v.size() << "\n";
// }