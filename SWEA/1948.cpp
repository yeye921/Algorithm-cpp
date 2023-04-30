// 월 일로 이루어진 날짜를 2개 입력 받아, 두번째 날짜가 첫번째 날짜의 며칠째인지 출력하는 문제
// 은근 어려움...
#include <iostream>
using namespace std;
int T, test_case;
int mon1, mon2;
int day1, day2;
int MonToDay(int month){
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return 31;
    } else if(month == 2){
        return 28;
    } else {
        return 30;
    }
}
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        int ret = 0;
        cin >> mon1 >> day1 >> mon2 >> day2;
        
        // 둘이 겉은 달이면 날짜끼리만 빼면 됨
        if(mon1 == mon2) ret = day2 - day1 + 1;
        else {
            // 둘이 다른 달이면 쪼금 복잡함
            // 1. 첫번째 달의 날짜 ~ 그 달의 끝날짜까지 일 수 계산
            // 2. mon1 + 1 ~ (mon2 - 1)까지 1씩 증가시키면서 해당 달의 날짜 계산
            // 3. mon2의 날짜 계산
            int endDay = MonToDay(mon1);
            ret += endDay - day1 + 1;
            for(int i = mon1 + 1; i <= mon2 - 1; i++){
                ret += MonToDay(i);
            }
            ret += day2;
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}