// 거꾸로 읽어도 제대로 읽은 것과 같은 문장이면 1을 출력하고 아니라면 0을 출력한다
// 문자열 거꾸로 하는 함수: reverse(str.begin(), str.end());
// (주의: 이 함수는 리턴값이 void이고 str자체를 변경시키는 함수이다!!)
#include <iostream>
#include <algorithm> // for reverse 함수
using namespace std;
string s;
int test_case;
int main(){
    cin >> test_case;
    for(int i = 1; i <= test_case; i++){
        cin >> s;
        string start = s;
        reverse(s.begin(), s.end());
        if(start == s) cout << "#" << test_case << " " << "1\n";
        else cout << "#" << i << " " << "0\n";
    }
}