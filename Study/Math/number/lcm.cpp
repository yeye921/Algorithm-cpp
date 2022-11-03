// 최소공배수를 구하는 방법
// a * b = 두 수의 최대공약수 * 최소공배수 이용
// 두 수의 최소공배수 = (a * b) / 최대공약수
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){ 
    if(a == 0) return b; // a < b를 의미, a자리에 나머지가 들어감
    return gcd(b % a, a);
}
int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}
int main(){
    int a = 10, b = 12; // 여기서 a < b가 아니면 swap을 해줘야함
    cout << lcm(a, b) << "\n";
    return 0;
}