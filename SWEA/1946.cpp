// m1) 한 문자열에 다 때려넣고 10자씩 끊어서 출력하기
#include <iostream>
using namespace std;
int T, test_case, n;
int num;
char ch;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin >> n;
        string ret = "";
        for(int i = 0; i < n; i++){
            cin >> ch >> num;
            // 횟수만큼 문자를 문자열에 더하기
            for(int j = 0; j < num; j++) ret += ch;
        }

        cout << "#" << test_case << "\n";
        cout << ret << "\n" << ret.size() << "\n";
        
        // 10개씩 끊어서 출력
        for(int i = 0; i < ret.size(); i++){
            cout << ret[i];
            // 예외: 인덱스가 9, 19, 29, ... 이면서 문자열의 마지막 문자이면 => 개행 안해도 됨 
            // 9, 19, 29, .. 의 공통점: 10으로 나누었을 때 나머지가 9이다.
            if(i % 10 == 9 && i != ret.size()) cout << "\n";
        }
        cout << "\n";
    }
}