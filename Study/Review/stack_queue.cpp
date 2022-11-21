// 스택은 가장 마지막으로 들어간 데이터가 가장 첫번째로 나오는 성질을 가진 자료구조!
// 문자열 폭발, 아름다운 괄호 만들기, 짝 찾기 문제 등에 쓰임

// 큐는 먼저 집어넣은 데이터가 먼저 나오는 성질을 가진 자료구조
// 주로 BFS에 쓰임

// 덱은 앞뒤로 참조가 가능한 자료구조

#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);
    cout << dq.front() << "\n";
    cout << dq.back() << "\n";
    cout << dq.size() << "\n";

    dq.pop_back();
    dq.pop_front();
    cout << dq.size() << "\n";
    return 0;
}