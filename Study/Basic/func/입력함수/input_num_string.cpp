// 따닥따닥 붙은 숫자를 입력받는 방법 1
#include<bits/stdc++.h>
using namespace std;
int n, m, a[10][10];
string s;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
       cin >> s;
       for(int j = 0; j < m; j++){
	       a[i][j] = s[j] - '0';  // 문자열 숫자에서 문자열 숫자 0을 뺌으로써 정수형 숫자로 만듬 (ex. '3' - '0' = 3)
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j];
            }
        cout << "\n";
    }
}
/*
4 4
1000
0000
0111
0000
1000
0000
0111
0000
*/

