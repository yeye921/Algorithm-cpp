// 표시해놓은 부분이 중요함!
#include <bits/stdc++.h>
using namespace std;
int n, score, mx;
double ret;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> score;
        mx = max(mx, score);
        ret += score;
    }
    // 고친 점수들의 평균 (고치는 것을 한번에 적용함)
    ret = (ret / mx * 100) / n;

    cout.precision(6); // 소수점 6번째자리까지 출력
    cout << ret << "\n";
}