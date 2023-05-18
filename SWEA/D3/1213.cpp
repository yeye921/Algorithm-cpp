// 주어진 문자열에서 특정한 문자열의 개수를 구하는 프로그램
#include <iostream>
using namespace std;
int T;
int main(){
    for(int test_case = 1; test_case <= 10; test_case++){
        cin >> T;
        int ret = 0;
        string key;
        string str;

        cin >> key >> str;
        // 해당 키워드가 문자열 내에 여러개 존재할 경우 => 하나씩 제거해가면서 찾음. 더이상 없으면 종료
        while(1){
            // cout << str.find(key) << "\n";
            auto idx = str.find(key);
            if(idx != string::npos){
                ret++;
                str.erase(idx, key.size());
            }
            else break;
        }
        cout << "#" << T << " " << ret << "\n";
    }
}