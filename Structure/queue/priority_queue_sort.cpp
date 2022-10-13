// 우선순위 큐는 priority_queue<자료형, 구현체, 비교연산자>가 들어감
// 우선순위 큐에 커스텀 정렬을 넣을 때는 반대로 생각해야함
#include <bits/stdc++.h>
using namespace std;
struct Point{
    int y, x;
    Point(int y, int x) : y(y), x(x){}
    Point(){y = -1; x = -1;}
    bool operator < (const Point &a) const {  // a = last
        return x > a.x;  // 원래: x를 기준으로 내림차순 정렬, 우선순위 큐 적용: x를 기준으로 오름차순 정렬
    }
};

priority_queue<Point> pq;
int main(){
    pq.push({1, 1});
    pq.push({2, 2});
    pq.push({3, 3});
    pq.push({4, 4});
    pq.push({5, 5});
    pq.push({6, 6});
    cout << pq.top().x << "\n"; // 알아서 커스텀 정렬 적용됨
    return 0;
}
/* 1 */