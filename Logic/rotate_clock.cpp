// 시계방향, 반시계 방향으로 회전해야 하는 로직
// rotate(first, middle, last): (first와 last사이에 있는 부분배열에서) middle이 가리키는 요소가 first로 가며 회전하는 것을 의미
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    for(int i = 1; i < 10; i++) v.push_back(i); // v = {1, 2, 3, 4, 5, 6, 7, 8, 9}

    // 앞으로 회전할 땐 이렇게 (ex. v = {2, 3, 4, 5, 6, 7, 8, 9, 1})
    // rotate(v,begin(), v.begin() + 1, v.end());

    // 뒤로 회전할 땐 이렇게 (ex. v = {9, 1, 2, 3, 4, 5, 6, 7, 8})
    rotate(v.begin(), v.begin() + v.size() - 1, v.end()); // v.begin() + v.size() = v.end() 

    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";
    return 0;
}