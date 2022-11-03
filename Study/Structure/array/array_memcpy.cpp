// 주로 배열을 복사할 때 사용
// memcpy(복사 받을 메모리를 가리키는 포인터, 복사할 메모리를 가리키는 포인터, 복사할 데이터의 길이)

// 아래와 같이 어떤 배열을 수정할 때 원본 배열을 온전히 저장하고 싶을 때 다음과 같이 씁니다
memcpy(temp, a, sizeof(a)); // temp라는 배열에 a를 담아둠
// a라는 배열을 수정하는 로직
memcpy(a, temp, sizeof(temp)); // a에 temp 배열을 복사해 다시 a를 만듬

#include <bits/stdc++.h>
using namespace std;
int a[5];
int temp[5];
int main(){
    for(int i = 0; i < 5; i++) a[i] = i;    // a = {0, 1, 2, 3, 4}
    memcpy(temp, a, sizeof(a));             // 배열 a를 temp에 복사
    for(int i : temp) cout << i << ' ';     // temp에 a가 복사된 것을 확인가능
    return 0;
}