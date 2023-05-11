// n의 m 거듭제곱 값을 구하는 프로그램을 재귀호출을 이용해 구현
// 결과값은 int 범위를 넘어가지 않는다
#include <iostream>
using namespace std;
int t;
int n, m;
int recursion(int idx, int ret){
    if(idx == m) return ret;
    else recursion(idx + 1, ret * n);
}
int main(){
    for(int i = 0; i < 10; i++){
        cin >> t;
        cin >> n >> m;
        int x = recursion(0, 1);
        cout << "#" << t << " " << x << "\n";
    }
}