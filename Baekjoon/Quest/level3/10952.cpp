// 기본 입출력에서 향상된 입출력으로 바꾸면 실행시간이 4ms > 0ms로 줄어듬
#include <bits/stdc++.h>
using namespace std;
int a, b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        cout << a + b << "\n";
    }
}