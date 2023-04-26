// 시 분으로 이루어진 시각을 2개 입력 받아, 더한 값을 시 분으로 출력하는 프로그램
// 시각은 1~12시, 분은 0~59
#include <iostream>
using namespace std;
#define min aaa
int T, t1, m1, t2, m2, hour, min;
int main(){
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> t1 >> m1 >> t2 >> m2;
        hour = t1 + t2;
        min = m1 + m2;
        if(min > 59) {
            hour += 1;
            min -= 60;
        }
        if(hour > 12) hour -= 12;
        cout << "#" << i << " " << hour << " " << min << "\n";
    }
    return 0;
}