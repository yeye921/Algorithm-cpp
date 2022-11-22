// 우리의 목표: 주어진 알파벳들을 가지고 펠린드롬 만들기 !
// 펠린드롬이 안되는 경우에 대한 처리 => 알파벳 개수 중 홀수가 2개 이상

// 알파벳 개수가 짝수개 일 때: ret에 앞/뒤로 붙임
// 알파벳 개수가 홀수개 일 때: 1개는 ret의 중앙에 삽입, 나머지는 짝수개 일 때처럼 앞/뒤로 붙임

// 문자를 문자열로 변환: char c = 'a'; string s; s = c;
#include <iostream>
using namespace std;
int flag, cnt[94], n; // 알파벳들의 개수를 세는 것
string s, ret, mid_;
char mid;
int main(){
    cin >> s;
    for(char c : s) cnt[c]++;

    for(int i = 'Z'; i >= 'A'; i--){ // 사전순으로 앞서려면 뒤에걸 먼저 붙임
        if(i){
            if(cnt[i] & 1){ // 홀수개 일 때
                mid = (char)i;
                flag++;
                cnt[i]--;
            }
            if(flag == 2) break; // 알파벳 개수 중 홀수가 2개 이상 => 펠린드롬 불가

            // 짝수개 일 때 => 앞뒤로 붙이는 방법 여러가지 존재
            // for(int j = 0; j < cnt[i]; j+=2){
            //     ret = (char)i + ret;
            //     ret += (char)i;
            // }
            n = cnt[i] / 2;
            ret.insert(ret.size(), n, (char)i);
            ret.insert(0, n, (char)i);
        }
    }
    
    if(flag == 2) cout << "I'm Sorry Hansoo\n";

    // mid삽입 & ret 출력
    else{
        if(mid){
            mid_ = mid;
            ret.insert(ret.size() / 2, mid_);
        }
        cout << ret << "\n";
    }
}