// bool은 0이면 false, 0이 아닌 값들은 모두 true
// false는 0, true는 1
// bool()을 통해 간단하게 bool형으로 형변환이 가능함
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a = -1;
    cout << bool(a) << "\n";
    a = 0;
    cout << bool(a) << "\n";
    a = 1;
    cout << bool(a) << "\n";
}
/*
1
0
1
*/
