// 입출력 성능 향상을 위한 문제
#include <bits/stdc++.h>
using namespace std;
int T, a, b;
int main(){
    // C++의 입출력 스트림(cin, cout)과 C표준 입출력 함수사이의 동기화를 끊어준다 > C++의 입출력 스트림이 더 빠르게 동작한다
    ios_base::sync_with_stdio(false);

    // cin과 cout은 서로 묶여있어 cin에서 입력을 받으면 cout에 대한 출력이 버퍼링되어 느려질 수 있다
    cin.tie(NULL); // cin과 cout의 묶임을 

    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> a >> b;
        cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
    }
}