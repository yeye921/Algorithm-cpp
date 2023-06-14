// m1) n자리 숫자를 string으로 받고 각자리 숫자를 더하기
// m2) 나누기를 이용한 방법 => 불가함. n의 범위가 0~100이라 정수나 실수로 해결하는데 한계가 있음
#include <bits/stdc++.h>
using namespace std;
int n, ret;
string str;
int main(){
    cin >> n;
    cin >> str;
    for(int i = 0; i < n; i++){
        ret += str[i] - '0'; // '1'을 1로 변환하는 방법
    }
    cout << ret << "\n";
}