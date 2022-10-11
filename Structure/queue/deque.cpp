// queue는 앞에서만 꺼낼 수 있지만 deque는 앞뒤로 참조가 가능한 자료구조
// push_front(), push_back(), pop_front(), pop_back() 함수 존재
#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);      // dq = {1, 2, 3}
    cout << dq.front() << "\n";
    cout << dq.back() << "\n";
    cout << dq.size() << "\n";
    dq.pop_back();
    dq.pop_front();
    cout << dq.size() << "\n";
    return 0;
}