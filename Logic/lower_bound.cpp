// lower_bound(시작주소, 끝+1주소, x): "x값 이상이 되는 위치"를 반환함
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    vector<int> a;
    for(int i = 1; i <= 3; i++) a.push_back(i);  // a = {1, 2, 3}
    for(int i = 5; i <= 10; i++) a.push_back(i); // a = {1, 2, 3, 5, 6, 7, 8, 9, 10}

    // 반환되는 값은 이터레이터이기 때문에 배열의 처음 주소값인 v.begin()또는 a[0]을 빼주어서 
    // => int형으로 몇번째인지를 파악할 수 있음
    cout << lower_bound(a.begin(), a.end(), 4) - a.begin() << "\n"; // 값이 4 이상이 되는 위치 = 5의 위치 = 3번째
    return 0;
}