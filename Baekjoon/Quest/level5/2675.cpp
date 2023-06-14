// p에 누적을 해서 문자열을 새로 만들어도 되지만 그냥 출력해도 된다!
#include <iostream>
using namespace std;
int T, cnt;
string s;
int main(){
    cin >> T;
    for(int i = 0; i < T; i++){
        string p;
        cin >> cnt >> s;
        for(int i = 0; i < s.length(); i++){ 
            for(int j = 0; j < cnt; j++){ // 각 s[i]를 cnt만큼 반복해서 누적함
                p += s[i]; // cout << s[i]; 로 대신해도 된다!
            }
        }
        cout << p << "\n";
    }
}