// 최소 몇번 양을 세었을때 이전에 봤던 숫자들의 자릿수에서 0~9까지의 숫자를 보게되는지 출력
// 0~9까지의 숫자가 있다는 것을 확인하는 방법 => set자료형의 개수가 10개인지 확인
#include <iostream>
#include <cstdlib>
#include <set>
using namespace std;
int T;
int n;
string s;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        set<int> st;
        cin >> n;
        int idx = 1;
        int x = n;
        while(1){
            // 숫자를 자리별로 끊어서 넣기
            s = to_string(x);
            for(int i = 0; i < s.size(); i++){
                st.insert(s[i] - '0'); // 문자를 숫자로 변환
            }
            if(st.size() == 10) break;
            idx++;
            x = n * idx;
        }      
        cout << "#" << test_case << " " << s << "\n";
    }
}