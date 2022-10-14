// 배열과 포인터
// 배열의 이름(arr)은 배열의 시작주소를 가리킴
// arr + 2는 배열의 이름부터 두번째 배열 요소임
// 따라서 아래처럼 넘겨도 값들이 수정됨
#include <bits/stdc++.h>
using namespace std;
void go(int a[]){
    a[2] = 100;
}
int a[3] = {1, 2, 3};

int main(){
    go(a);
    for(int i : a) cout << i << "\n";
    return 0;
}