// 10개의 수를 입력 받아, 그 중에서 홀수만 더한 값을 출력하기
// 홀수 판단하는 방법: m1) num % 2 == 1, m2) num & 1 == 1
#include <iostream>
using namespace std;
int test_case, num;
int main(){
    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        int ret = 0;
        for(int i = 0; i < 10; i++){
            cin >> num;
            if(num & 1) ret += num;
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
    return 0;
}