// 1부터 n까지의 숫자에서 홀수는 더하고 짝수는 뺏을 때 최종 누적된 값을 구하는 문제
#include <iostream>
using namespace std;
int t, n, ret;
int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
        int ret = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            if(i & 1) ret += i;
            else ret -= i;
        }
        cout << "#" << i << " " << ret << "\n";
    }
    return 0;
}