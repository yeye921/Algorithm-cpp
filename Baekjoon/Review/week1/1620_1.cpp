// int - string 매핑에 Arr사용함으로써 이전보다 시간 더 단축됨 !
#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, pb;
// map<int, string> mp_i;
string mp_i[100000]; // !! int - string 매핑
map<string, int> mp_s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s;
        mp_i[i] = s;
        mp_s[s] = i;
    }
    for(int i = 0; i < m; i++){
        cin >> pb;
        if(atoi(pb.c_str()) == 0){ // 문자이면
            cout << mp_s[pb] << "\n";
        } else {
            cout << mp_i[atoi(pb.c_str())] << "\n";
        }
    }
    return 0;
}