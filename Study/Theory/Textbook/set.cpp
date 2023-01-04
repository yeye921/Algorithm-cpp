#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int main(){
    s.insert(12);
    s.insert(10);
    s.insert(22);
    s.insert(2);
    s.insert(85);
    s.insert(22);

    cout << "자동으로 정렬된 후 출력: ";
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";

    auto it1 = s.find(10);
    auto it2= s.find(85);

    s.erase(it1, it2); // 10부터 85이전까지 삭제                                                    
    cout << "삭제 후 출력: ";
    for(auto it = s.begin(); it != s.end(); it++){
        cout << (*it) << " ";
    }
    cout << "\n";
}