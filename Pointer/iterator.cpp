// iterator는 컨테이너(배열 등)의 "메모리 주소를 가리키는 포인터"
// 많이쓰는 함수로는 begin(), end()가 있음
// begin(): 컨테이너의 시작 위치를 반환하는 데 사용됨
// end(): 컨테이너의 끝 + 1의 위치를 반환하는 데 사용됨
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    for(int i = 1; i <= 5; i++) v.push_back(i);   // v = {1, 2, 3, 4, 5}
    for(int i = 0; i < 5; i++){
        cout << i << "번째 요소 : " << *(v.begin() + i) << "\n";  // *를 주소값앞에 사용함으로써 요소에 접근 가능
        cout << &*(v.begin() + i) << "\n";  // 이터레이터를 기반으로 주소값 출력
    }
    // cout << v.begin() + i << "\n"; // 에러남
}
// 이터레이터는 바로 주소값을 반환하지 않아서 만약 이터레이터를 기반으로 주소값을 출력하려면 (&*)를 통해 출력해야함