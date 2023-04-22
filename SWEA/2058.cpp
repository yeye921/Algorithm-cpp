// 하나의 자연수를 입력 받아 각 자릿수의 합을 계산하는 프로그램
// m1) string > char > int로 변환해서 합치기
// m2) 10으로 나눠가면서 10으로 나눈 몫을 계속 더하기 (ex. 6789%10 = 9, 678%10=8, 67%10=7, 6%10=6 =>  9+8+7+6) 

// 정수의 n제곱 구하는 법: pow(num, n)
// 정수의 양의 제곱근 구하는 법: sqrt(n)
#include <iostream>
using namespace std;
int n, ret;
int main(){
    cin >> n;
    while(n > 0){
        ret += n % 10;
        n /= 10;
    }
    cout << ret << "\n";
}