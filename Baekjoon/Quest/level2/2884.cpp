// 45분 일찍 알람 설정하기
// 24시간 표현에서 하루의 시작은 0:0(자정)이고 끝은 23:59(다음날 자정 1분 전)이다
// 시간을 나타낼 때, 불필요한 0은 사용하지 않는다
// ex. 0 30 > 23 45
#include <bits/stdc++.h>
using namespace std;
int H, M;
int main(){
    cin >> H >> M;
    if(M < 45){
        if(H < 1) H = 24;
        H--;
        M = M + 60 - 45;
    }
    else {
        M -= 45;
    }
    cout << H << " " << M << "\n";
    return 0;
}