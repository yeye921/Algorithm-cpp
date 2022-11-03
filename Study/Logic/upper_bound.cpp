// lower_bound(): 어떠한 값 이상인 것의 위치 = 그 값 이상인 것의 위치
// upper_bound(): 그 값이 나오기 전의 위치 = "그 값보다 첫번째로 큰 수의 위치" (뒤에서부터 탐색)
// 둘은 이터레이터를 반환하기 때문에 꼭 시작주소를 빼줘서 int형으로 몇번째인지 파악하자

#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    for(int i = 2; i <= 5; i++) v.push_back(i); // v = {2, 3, 4, 5}
    v.push_back(7); // v = {2, 3, 4, 5, 7}

    cout << upper_bound(v.begin(), v.end(), 6) - v.begin() << "\n"; // 6이상의 값을 가지는 것의 위치 = 4번쩨
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() << "\n"; // 6이 나오기 전의 위치 = 4

    // 만약 원소를 못찾을 경우 다음과 같이 반환함 => "값이 없다면 그 근방지점을 반환함"
    cout << upper_bound(v.begin(), v.end(), 9) - v.begin() << "\n"; // 9가 나오기 전의 위치 => 가장 마지막 위치(5) 반환
    cout << lower_bound(v.begin(), v.end(), 9) - v.begin() << "\n"; // 9이상인 것의 위치 => ..
    cout << upper_bound(v.begin(), v.end(), 0) - v.begin() << "\n"; // 0이 나오기 전의 위치 => 가장 첫번째 위치 반환
    cout << lower_bound(v.begin(), v.end(), 0) - v.begin() << "\n"; // 0이상인 것의 위치 => ..
}