// 종말의 숫자란 어떤 수에 6이 적어도 3개이상 연속으로 들어가는 수
// ex. 제일 작은 종말의 숫자는 666 > 1666 > 2666 > ...

// N번째 영화의 제목에 들어간 숫자를 출력하는 프로그램 (1 <= N <= 10000)
// 모르겠으면 작은 예제라도 풀 수 있게 짜자 !!

// 숫자를 문자열로 변환하는 방법: to_string(숫자)
#include <bits/stdc++.h>
using namespace std;
int n, cnt, num;
int main(){
    num = 666;
    cin >> n;
    while(n != cnt){
        num++;
        if(to_string(num).find("666") != string::npos){
            cnt++; // 숫자가 666을 포함하고 있으면 카운트 증가
            cout << cnt << ":" << num << "\n"; // for 디버깅
        }
    }
    cout << num << "\n"; // n == cnt일 경우
    return 0;
}