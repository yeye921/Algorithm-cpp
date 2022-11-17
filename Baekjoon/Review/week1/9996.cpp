#include <bits/stdc++.h>
using namespace std;
int n;
string s, pattern, pre, suf;
int main(){
    cin >> n;
    cin >> pattern;

    int pos = pattern.find("*");
    pre = pattern.substr(0, pos);
    suf = pattern.substr(pos + 1);

    for(int i = 0; i < n; i++){
        cin >> s;
        // 여기에 로직 들어가서 cout해야함
        if(pre.size() + suf.size() > s.size()){
            cout << "NE\n";
        } 
        else {
            if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
            else cout << "NE\n";
        }
    }
    return 0;
}