// 승수 구하는 법 -> pow 사용
#include <bits/stdc++.h>
using namespace std;
int main(){
    int m = 3;
    int n = 2;
    int pow_2 = (int)pow(m, n); // m의 n승을 반환하는 함수
    cout << pow_2 << "\n";
    return 0;
}
// +) pow함수는 double형이 기본이기 때문에 int형으로 사용하고 싶으면 (int)로 형변환 꼭 해줘야 함!