// 함수를 통해 어떤 값을 변화시키고 싶으면 주소값을 넘겨야 함(그래야 해당 메모리 위치로 들어가 값 변화시킬 수 있음)
#include <bits/stdc++.h>
using namespace std;
int idx = 2;
// call by reference
void go(int &idx){
    idx = 1;
}
// call by value
void go2(int idx){
    idx = 100;
}
int main(){
    go(idx);
    cout << idx << "\n";   // 1 : 값 바뀜
    go2(idx);
    cout << idx << "\n";   // 1: 값 안바뀜
    return 0;
}