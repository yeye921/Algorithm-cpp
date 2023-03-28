// 윤년일 경우 
// 1. 4의 배수이면서, 100의 배수가 아닐 때
// 2. 400의 배수일 때
#include <bits/stdc++.h>
using namespace std;
int year;
int main(){
    cin >> year;
    if(year % 4 == 0 && year % 100 != 0) cout << "1\n";
    else if(year % 400 == 0) cout << "1\n";
    else cout << "0\n";
    return 0;
}