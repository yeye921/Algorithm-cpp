// 사분면 고르기
// Quadrant n은 제 n사분면이라는 뜻이다
// 1사분면: x, y 좌표 모두 양수이다, 2사분면: x=음수, y=양수
// 3사분면: x, y 좌표 모두 음수이다, 4사분면: x=양수, y=음수
#include <bits/stdc++.h>
using namespace std;
int x, y;
int main(){
    cin >> x;
    cin >> y;
    if(x > 0){
        if(y > 0) cout << "1\n";
        else if(y < 0) cout << "4\n"; // 혹시 입력에 y=0을 받을 수 있으니까 else대신 else if 사용한 것임 (이 문제에서는 그럴 일 없음)
    }
    else if(x < 0){
        if(y > 0) cout << "2\n";
        else if(y < 0) cout << "3\n";
    }
    return 0;
}