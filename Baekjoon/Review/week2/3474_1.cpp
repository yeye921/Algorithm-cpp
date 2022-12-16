// 이 문제는 코드보다 풀이를 생각해내는게 핵심임
#include <bits/stdc++.h>
using namespace std;
int t, n, cnt2, cnt5;
int main(){
    // 아래 코드 없으면 시간초과 남
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        cnt2 = 0, cnt5 = 0; // 초기화 중요!! (이것 때문에 틀람)

        // 로직이 들어가야함
        for(int i = 2; i <= n; i*=2){
            cnt2 += n / i;
        }
        for(int i = 5; i <= n; i*=5){
            cnt5 += n / i;
        }
        cout << min(cnt2, cnt5) << "\n";
    }
    return 0;
} 