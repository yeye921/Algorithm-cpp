// 각 문자열의 길이는 30, 마디의 최대 길이는 10
// 패턴에서 반복되는 부분을 마디라고 함. 마디의 길이를 출력하는 문제
// 규칙: 반복되는 마디 중 가장 짧은 것 & 바로 뒤에 반복되는 마디가 또 나와야 함
#include <iostream>
using namespace std;
int T, test_case;
string str;
int ret;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin >> str;
        // 문자열을 어떻게 자를 것인가.... 마디의 길이는 최대 10
        for(int i = 1; i <= 10; i++){
            int len = i; // 마디의 길이
            string madi = str.substr(0, i);

            // 마디가 반복되는지 확인
            string next = str.substr(i, i);
            if(madi == next){
                ret = i;
                break; // 마디 중 가장 짧은 걸 선택해야하므로 첫번째로 조건을 만족하는 것을 마디로 함
            }
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}