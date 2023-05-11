// 실수 팁: ret의 값이 100만 * 1만으로 매우 커질 수 있으니 long long으로 선언하는게 중요함!
// 두번째 방법보다 이 방법이 훨씬 효율적이다. 1번 탐색으로 끝낼 수 있음.

// 규칙1: if(n < max) ret += (max - n)
// 규칙2: else max = n;
#include <iostream>
using namespace std;
int T, test_case;
int n, num;
int map[1000004];
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        long long ret = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> num;
            map[i] = num;
        }

        int mx = map[n-1];
        for(int i = n - 1; i >= 0; i--){
            if(mx > map[i]){
                ret += (mx - map[i]);
            }
            else mx = map[i];
        }
        cout << "#" << test_case << " " << ret << "\n";
    }

}