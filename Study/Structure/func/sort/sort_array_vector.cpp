// sort(first, last, *커스텀비교함수): 배열 등 컨테이너들의 요소를 정렬하는 함수
// first: 정렬하고 싶은 배열의 첫번째 이터레이터
// last: 정렬하고 싶은 배열의 마지막 이터레이터, 마지막 원소 그 다음의 위치를 가리켜야 함
// 커스텀비교함수(선택) : default로 오름차순, greater<int>(): 내림차순, less<int>(): 오름차순

#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int b[5];
int main(){
    for(int i = 5; i >= 1; i--) b[i - 1] = i;   // b = {1, 2, 3, 4, 5}
    for(int i = 5; i >= 1; i--) a.push_back(i); // a = {5, 4, 3, 2, 1}

    // 오름차순
    sort(a.begin(), a.end());   // vector 정렬
    sort(b, b + 5);             // array 정렬
    for(int i : a) cout << i << ' ';
    cout << '\n';
    for(int i : b) cout << i << ' ';
    cout << '\n';

    // 오름차순 2
    sort(a.begin(), a.end(), less<int>());
    sort(b, b + 5, less<int>());
    for(int i : a) cout << i << ' ';
    cout << '\n';
    for(int i : b) cout << i << ' ';
    cout << '\n';

    // 내림차순
    sort(a.begin(), a.end(), greater<int>());
    sort(b, b + 5, greater<int>());
    for(int i : a) cout << i << ' ';
    cout << '\n';
    for(int i : b) cout << i << ' ';
    cout << '\n';

    return 0;
}