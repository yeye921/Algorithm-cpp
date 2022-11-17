// 불가능한 경우: 알파벳의 개수 중 홀수가 2개 이상일 때
// 생각으로 안되면 일단 해보는게 중요 ex) aaa, aba, abb, ..

// 이 문제는 잘 모르겠으면 다시 강의 보기
// 알파벳이 AAAA, BB, CCC 이렇게 있을 때 -> AABCCCBAA 이런식으로 붙여야 사전순으로 앞서게 됨!
// 홀수 판단법: & 1 또는 %2 == 1
#include <bits/stdc++.h>
using namespace std;
string s, ret;
int cnt[200], flag;
char mid;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> s;

    // 일단 카운팅 배열로 문자를 카운팅해놓음 (ex. A:3, B:1)
    for(char a : s) cnt[a]++;

    // Z ~ A순으로 붙임 (for 사전순)
    for(int i = 'Z'; i >= 'A'; i--){
        if(cnt[i]){
            if(cnt[i] & 1){ // 문자가 홀수개이면
                mid = char(i); flag++;
                cnt[i]--;
            }
            if(flag == 2) break;
            for(int j = 0; j < cnt[i]; j += 2){
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }
    if(mid) ret.insert(ret.begin() + ret.size() / 2, mid);
    if(flag == 2) cout << "I'm Sorry Hansoo\n";
    else cout << ret << "\n";

    return 0;
}