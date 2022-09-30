// bool은 0이 아니면 true, 0이면 false
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
