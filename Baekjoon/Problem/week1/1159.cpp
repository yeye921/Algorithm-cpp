// 카운팅은 맵 또는 배열 !
// 아스키코드는 문자와 숫자를 매핑시켜놓은 것 (ex. 'a' <-> 97)
#include <bits/stdc++.h>
using namespace std;
int N, cnt[26]; // cnt 배열
string s, ret;
int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> s;
        cnt[s[0] - 97]++; // 문자 -> 숫자화 (선수의 성이 해당되는 알파벳에 +1) (97대신 'a'도 괜찮음)
    }

    // cnt배열 돌면서 같은 성을 가진 선수가 5명 이상인 것 찾기
    for(int i = 0; i < 26; i++){
        if(cnt[i] >= 5){ 
            ret += (char)(i + 97); // !! 숫자 -> 문자화 (97대신 'a'도 괜찮음)
        }
    }

    if(v.empty()){ // !! 벡터가 비어있는지 확인 (v.size() == 0)보다 많이 사용
        cout << "PREDAJA\n";
    } else {
        cout << ret << "\n";
    }

    return 0;
}