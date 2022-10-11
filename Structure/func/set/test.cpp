#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int main(){
    s.insert(12);
    s.insert(10);
    s.insert(12);
    s.insert(10);
    s.insert(2);
    s.insert(10);
    s.insert(90);
    s.insert(85);
    s.insert(45);
    
    cout << "Multiset elements after sort" << "\n";
    for(auto it : s) cout << it << " ";
    cout << "\n";

    return 0;
}