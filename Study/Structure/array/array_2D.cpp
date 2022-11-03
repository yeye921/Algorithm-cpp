// 2차원 배열 탐색, 출력
// 첫번째 차원 > 두번째 차원 순으로 탐색하는게 성능이 좋다
#include <bits/stdc++.h>
using namespace std;
const int mxy = 3;
const int mxx = 4;
int a[mxy][mxx];
int main(){
    for(int i = 0; i < mxy; i++){
        for(int j = 0; j < mxx; j++){
            a[i][j] = (i + j);
        }
    }

    // good
    for(int i = 0; i < mxy; i++){
        for(int j = 0; j < mxx; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    // bad
    for(int i = 0; i < mxx; i++){
        for(int j = 0; j < mxy; j++){
            cout << a[j][i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}