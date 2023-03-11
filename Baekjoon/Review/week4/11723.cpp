// XOR연산: 같으면 0, 다르면 1 반환 
#include <bits/stdc++.h>
using namespace std;
int m, n, x, flag;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> s;
        if(s[0] == 'a' && s[1] == 'l') n = (1 << 21) - 1;
        else if(s[0] == 'e') n = 0;
        else {
            cin >> x;
            if(s[0] == 'a') n |= (1 << x); // x는 1부터 시작 (2(=10))
            else if(s[0] == 'r') n &= ~(1 << x);
            else if(s[0] == 'c'){
                if(n & (1 << x)) cout << 1 << "\n";
                else cout << 0 << "\n";
            }
            else if(s[0] == 't') n ^= (1 << x);
        }
    }
    return 0;
}