// cin과 cout만 쓸 경우에는 시간초과가 난다. 
// m1) 아래와 같이 iostream의 default 설정을 수정해준다
// m2) c표준 입출력 stdio.h 쓰기
#include <bits/stdc++.h>
using namespace std;
int T;
int a, b;
int main(){
    ios_base::sync_with_stdio(false); // c와 c++의 표준 스트림 동기화를 끊는다 (원래 둘은 동일한 버퍼를 공유한다 > 버퍼를 분리해줌)
    cin.tie(NULL); // 입력과 출력 연결을 끊어준다 (cin으로 데이터를 읽을 때, 출력 버퍼에 있는 내용을 비우는데, 비우지 않고 먼저 입력하게 함)
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> a >> b;
        cout << a+b << "\n";
    }
}