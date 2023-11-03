// We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid. A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.

// confusing number 조건
// 1. 각자리 수가 유효해야함
// 2. 180도 회전 했을 때 다른 숫자가 되어야 함 (중요!! 180도 회전 = 숫자가 문제에서 주어진대로 바뀌고 앞뒤 순서도 바뀐다!) > 이 부분에서 틀렸음
#include <bits/stdc++.h>
using namespace std;
bool game(int n){
    string s = to_string(n);
    string num = "";

    for(int i = s.size() - 1; i >= 0; i--){
        // 1을 판단
        if(s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '7') return false;

        // 2를 판단
        if(s[i] == '0') num += '0';
        if(s[i] == '1') num += '1';
        if(s[i] == '6') num += '9';
        if(s[i] == '8') num += '8';
        if(s[i] == '9') num += '6';
    }
    cout << n << " == " << num << "\n";
    return n != stoi(num);
}
int main(){
    int n;
    while(cin >> n){
        bool sol = game(n);
        cout << sol << "\n";
    }
    return 0;
}