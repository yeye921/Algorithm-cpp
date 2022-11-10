#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[26];
int main(){
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        cnt[s[i] - 97]++;
    }

    for(int i = 0; i < 26; i++) cout << cnt[i] << " ";
    return 0;
}