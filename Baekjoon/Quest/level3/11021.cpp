// c++의 입출력은 기본적으로 c의 기본 입출력과 동기화 되어있어서 상대적으로 느리다
// 그래서 두 io의 동기화를 끊어주고 입력과 출력 묶음을 풀어주면 성능적으로 이득을 볼 수 있다.
#include <bits/stdc++.h>
using namespace std;
int T;
int a, b;
int main(){
    // 아래 두줄을 추가하면 향상된 입출력이다. (default는 기본 입출력)
    ios_base::sync_with_stdio(false); // c와 c++의 표준 입출력 동기화를 해제함
    cin.tie(NULL); // 입력과 출력이 묶여있는 것을 풀어준다

    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << "\n";
    }
}