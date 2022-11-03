// 따닥따닥 붙은 숫자를 입력받는 방법 2
#include <bits/stdc++.h>
using namespace std;
int a[10][10], n, m;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]); // 한자리 만의 int를 입력받음
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}