// 이 문제의 시사점: EOF(End of File)는 파일의 끝을 알리는 함수로 -1의 값을 가지며, 콘솔 창에서는 ctrl+Z
// C++에서는 cin.eof()함수가 bool타입을 가지며 EOF를 읽으면 true값으로 바뀌게된다
// 또한, while문의 조건 안에 cin함수를 직접 넣어 정상적인 입력이 아닐 시 자동적으로 종료되게 할 수 있다
#include <bits/stdc++.h>
using namespace std;
int a, b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   // m1)
    while(cin >> a >> b){
        cout << a + b << "\n";
    }
    /*
    m2) while(1){
        cin >> a >> b;
        if(cin.eof() == true){
            break;
        }
    }
    */
}