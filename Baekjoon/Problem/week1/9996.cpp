// 모르겠는 것
// 문자열 자르기 => split이용
// 문자열 내 해당 문자의 위치 찾기 => find이용
// erase의 두번째 인자는 포함되지 않음 (그전까지 지움)
#include <bits/stdc++.h>
using namespace std;
int N;
int pos;
string pattern, s, a, b;
vector<string> v;
void split(string input, string delimeter){
    while((pos = input.find(delimeter)) != string::npos){
        a = input.substr(0, pos);
        input.erase(0, pos + delimeter.size()); // 처음~ 구분자까지 포함해서 자름
        b = input;
    }
}
string sol(string s){
    int ia = s.find(a);
    int ib = s.find(b);
    if(a.size() > 1) ia = s.find(a) + a.size(); // ia는 a의 끝 인덱스

    while(ib != string::npos){ // s에서 b를 찾을 수 없을 때 까지 반복
        if(ia < ib){
            // 성공
            return "DA";
        } else {
            // s에서 b를 없애고 다음 b를 찾음
            pos = s.find(b);
            s.erase(pos, pos + b.size()); // 이게 최선일까...?
            ib = s.find(b);
        }
    }
    return "NE";

    // if(ia != string::npos && ib != string::npos){
    //     if(a.size() > 1){
    //         if(ia + a.size() < ib) return "DA";
    //     } else{
    //         if(ia < ib) return "DA";
    //     }
    // }
    // return "NE";

}
int main(){
    cin >> N;
    cin >> pattern;

    // 패턴을 별표를 기준으로 앞/뒤로 자름
    split(pattern, "*");

    for(int i = 0; i < N; i++){
        cin >> s;

        // 여기에 판단하는 로직 들어감
        v.push_back(sol(s));
    }

    for(string s : v) cout << s << "\n";

    return 0;
}