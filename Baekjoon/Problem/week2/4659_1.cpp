#include <bits/stdc++.h>
using namespace std;
#define prev aaa
string s;
bool is_vowel(int idx){
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}
int main(){
    while(1){
        cin >> s;
        if(s == "end") break;

        // 각 테스트 케이스마다 초기화 !!
        int lcnt = 0, vcnt = 0;
        bool is_include_v = 0, flag = 0;
        int prev = -1;
        
        for(int i = 0; i < s.size(); i++){
            int idx = s[i];
            // 1,2번 조건 체크
            if(is_vowel(idx)){ 
                lcnt++; vcnt = 0; is_include_v = 1;
            } else { 
                lcnt = 0; vcnt++;
            }
            if(lcnt == 3 || vcnt == 3) flag = 1; // 2번조건 체크하는데 요 처리가 중요함 !!
            // cout << lcnt << ":" << vcnt << ":" << flag << "\n";

            // 3번 조건 체크 => 스킬: prev라는 것을 사용하면 됨 !!
            // cout << "비교 " << char(prev) << ":" << char(idx) << "\n"; // for 디버깅
            if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')) flag = 1; // 같은 글자가 연속적으로 오고 ee나 oo가 아닐 경우
            prev = idx; // 이전 값을 prev에 저장하여 현재 값과 비교
        }
        // 조건 만족 못하는 것들을 flag = 1로 설정하여 처리하기
        if(is_include_v == 0) flag = 1;
        if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
        else cout << "<" << s << ">" << " is acceptable.\n";
    }
    return 0;
}