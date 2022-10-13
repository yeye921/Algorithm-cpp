// 우선순위 큐: 들어간 순서에 상관없이 "우선순위가 높은 데이터가 먼저 나가는" 형태
// 내부구조는 heap으로 구현되어 있음, 주로 다익스트라, 그리디 등에 쓰임
// greater를 써서 오름차순, less를 써서 내림차순으로 바꿀 수 있음
// priority_queue<자료형, 구현체, 비교연산자>의 형태
#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순
// priority_queue<int, vector<int>, less<int>> pq; // 내림차순
int main(){
    pq.push(5);
    pq.push(4);
    pq.push(3);
    pq.push(2);
    pq.push(1);  // 오름차순이니까 1,2,3,4,5
    cout << pq.top() << "\n"; // top(): 우선순위 큐에서 top에 있는 원소, 즉 우선순위가 높은 원소 반환함
    return 0;
}
/* 1 */