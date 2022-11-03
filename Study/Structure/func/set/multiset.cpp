// multiset: 중복되는 원소도 집어넣을 수 있는 자료구조
// key,value 형태로 집어넣을 필요도 없고, 넣으면 "자동적으로 정렬"되는 편리한 자료구조이다.
// 아래처럼 erase, find, insert가 가능함
#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int main(){
    s.insert(12);
    s.insert(10);
    s.insert(2);
    s.insert(10);
    s.insert(90);
    s.insert(85);
    s.insert(45);
    
    cout << "Multiset elements after sort" << "\n";
    // multiset 요소들 하나씩 탐색 by iterator?
    for(auto it = s.begin(); it != s.end(); it++)  // s.end()가 가리키는 것은 마지막 원소의 다음 위치
        cout << *it << " ";
    cout << "\n";

    // 더 쉬운 탐색법
    for(auto it : s) cout << s << " ";
    cout << "\n";

    // multiset의 find 함수
    auto it1 = s.find(10); // 10의 위치
    auto it2 = s.find(90); // 90의 위치
    if(it1 == s.end()){
        cout << "not found in it1" << "\n";
    } else {
        cout << "found in it1" << "\n";
    }
    if(it2 == s.end()){
        cout << "not found in it2" << "\n";
    } else {
        cout << "found in it2" << "\n";
    }

    // multiset의 erase 함수
    // 10부터 90전까지 원소들 지움
    s.erase(it1, it2);
    cout << "Multiset Elements after erase:\n";
    for(auto it = s.begin(); it != s.end(); it++)
        cout << (*it) << " ";
    cout << "\n";

    // 맨 처음 원소 지움
    s.erase(s.begin());
    for(auto it = s.begin(); it != s.end(); it++)
        cout << (*it) << " ";
    cout << "\n";

    return 0;
}