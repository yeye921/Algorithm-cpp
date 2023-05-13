// n과 루트n이 모두 펠린드롬이면, 이 수를 제곱 펠린드롬 수라고 한다
// A이상 B이하의 제곱 펠린드롬 수 찾기
// +) reverse는 원본 문자열을 변경하는 void형 함수이다
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int T;
int a, b;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        int ret = 0;
        cin >> a >> b;
        for(int i = a; i <= b; i++){
            // 제곱 펠린드롬인지 확인하기
            // 0. 루트 n이 정수인지 체크
            // 1. n과 루트 n이 펠린드롬인지 체크
            double n = sqrt(i);
            if(n == (int)n){
                string s = to_string(i);
                string e = s;
                reverse(e.begin(), e.end());
                if(s == e){
                    string ss = to_string((int)n);
                    string ee = ss;
                    reverse(ee.begin(), ee.end());
                    if(ss == ee) ret++;
                }
            }
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}