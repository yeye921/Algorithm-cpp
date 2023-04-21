// 10개의 수를 입력 받아, 평균값을 출력하는 프로그램
// 소수점 첫째 자리에서 반올림한 정수 출력

// m1) 배열의 총합 구하는 accumulate() 이용
// m2) 하나씩 입력받으면서 누적해서 총합계산

// 올림, 내림, 반올림 관련 함수
// double ceil(double n); //올림
// double floor(double n); //내림
// double round(double n); //반올림
#include <cmath>
#include <iostream>
using namespace std;
int test_case;
int num;
int times = 10;
double ret = 0;
int main (){
    cin >> test_case;
    for(int i = 0; i < test_case; i++){ // 테스트 케이스는 초기화가 중요!
        ret = 0;
        for(int i = 0; i < times; i++){
            cin >> num;
            ret += num;
        }
        ret  = round(ret / times); // 평균을 구한 뒤, 소수점 첫째자리에서 반올림
        cout << "#" << test_case << " " << ret << "\n";
    }
    return 0;
}