// pair & tuple 생성 및 출력 방법
// pair: 두가지의 값을 담을 때 사용
// tuple: 세가지 이상의 값을 넣을 때 사용
// tie(): pair또는 tuple에 들어있는 두가지 이상의 값을 꺼낼 때 사용

#include <bits/stdc++.h>
using namespace std;
pair<int, int> pi;
tuple<int, int, int> tl;
int a, b, c;
int main(){
    // pair 생성 방법 두가지
    pi = {1, 2};
    pi = make_pair(1, 2);

    // tuple 생성 방법 두가지
    tl = {1, 2, 3};
    tl = make_tuple(1, 2, 3); // tuple 생성

    tie(a, b) = pi;
    cout << a << ":" << b << "\n";

    tie(a, b, c) = tl;
    cout << a << ":" << b << ":" << c << "\n";

    return 0;
}