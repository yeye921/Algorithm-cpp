// double을 int로 변환하는 방법
// 그냥 앞에다 int로 선언해주기만 하면 됨
#include <bits/stdc++.h>
using namespace std;
int main(){
    double ret = 2.12345;
    int n = 2;
    int a = (int)round(ret / double(n));
    cout << a << '\n';
    return 0;
}