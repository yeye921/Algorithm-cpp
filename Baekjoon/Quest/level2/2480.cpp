// 3개의 주사위의 나온 눈이 주어질 때, 상금 계산하기
// 68%에서 틀림 => a,b,c가 모두 다른 경우에서 한 조건을 빼먹음
// 나중에 또 다시 풀어볼만한 문제
#include <bits/stdc++.h>
using namespace std;
int a, b, c, ret, mx;
int main(){
    cin >> a >> b >> c;
    if(a == b && b == c) ret = 10000 + (a * 1000); // a,b,c가 모두 같은 경우
    else if(a != b && b != c && c != a){ // a,b,c가 모두 다른 경우 (실수!! a != c 조건을 빼먹음!!)
        // 3개 중 가장 큰 수 찾기
        mx = max(a, b);
        mx = max(mx, c); // 여기서 조금 헷갈렸음
        ret = mx * 100;
    }
    // a,b,c 중 2개가 같은 경우
    else {
        if(a == b) ret = 1000 + (a * 100);
        else if(b == c) ret = 1000 + (b * 100);
        else if(a == c) ret = 1000 + (c * 100);
    }
    cout << ret << "\n";
}