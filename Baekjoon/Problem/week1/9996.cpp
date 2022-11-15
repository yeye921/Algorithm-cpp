// !! 패턴에 있는 별표를 알파벳 소문자로 이루어진 임의의 문자열로 변환해 파일 이름과 같게 만들 수 있어야 한다
// *의 앞 뒤에 한글자 이상도 올 수 있다
// prefix: *의 앞에 오는 것들, suffix: *의 뒤에 오는 것들
// prefix와 suffix를 나누는 것을 substr을 이용함

// 문자열.substr(시작주소, 개수): 문자열의 특정 위치부터 몇개까지를 자름
// 문자열.substr(시작주소): 문자열의 특정 위치부터 끝까지 자름
// 문자열.find("abc"): 문자열 내에서 특정 문자열 찾을 때 사용

// 우리는 접두사와 접미사의 길이만큼만 확인하면 됨 
// 즉, 문자열의 앞과 끝이 접두/접미사와 같은지만 체크하면 됨 !!
// +) 문자열의 사이즈 > 접두사 사이즈 + 접미사 사이즈 (=반례찾기)

#include <bits/stdc++.h>
using namespace std;
int n;
string s, pattern, pre, suf;
int main(){
    cin >> n;
    cin >> pattern;

    int pos = pattern.find("*"); // *를 기준으로 앞/뒤로 문자열 자름
    pre = pattern.substr(0, pos);
    suf = pattern.substr(pos + 1); // s.substr(first): 특정위치부터 끝까지 자르기

    for(int i = 0; i < n; i++){
        cin >> s;
        if(pre.size() + suf.size() > s.size()){ // But, 반례(ab*ab =/> ab)때문에 이 부분 필수!!
            cout << "NE\n";
        } 
        else { // 원래는 이 로직만으로도 풀림
            if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
            else cout << "NE\n";
        }
    }
    return 0;
}