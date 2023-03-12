// 숫자의 모든 자릿수가 1인지 확인하는 방법...?
#include <iostream>
using namespace std;
int n, cnt;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    while(cin >> n){
        // cout << n << "\n";
        int i = 1;
        long long ret = 1;
        while(1){
            cnt = 0;
            ret = n * i; // n의 배수

            // 여기가 너무 큼
            // ret의 모든 자릿수가 1인지 확인
            s = to_string(ret);
            cout << "s: " << s << "\n";
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '1') cnt++;
                else break; // 여기서 시간단축시켜줌
            }
            if(cnt == s.size()){ // 모든 자릿수가 1일 때 => 자릿수 출력
                cout << s.size() << "\n";
                break;
            }
            i++;
        }
    }
}