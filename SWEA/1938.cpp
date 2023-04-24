// 두 개의 자연수를 입력받아 사칙연산 수행하는 프로그램
// +) 나누기 연산에서 소수점 이하의 숫자는 버림
#include <iostream>
using namespace std;
int a, b;
int main(){
    cin >> a >> b;
    cout << a + b << "\n";
    cout << a * b << "\n";
    cout << (int)(a / b) << "\n";
}