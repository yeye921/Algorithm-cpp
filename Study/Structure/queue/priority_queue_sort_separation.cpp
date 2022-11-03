// 구조체 자체내에 커스텀 정렬을 구현하지 않고 따로 떼어서 함
#include <bits/stdc++.h>
using namespace std;
struct Point{
    int y, x;
};
struct cmp{
    bool operator()(Point a, Point b){ // a = first, b = last
        return a.x < b.x;              // x를 기준으로 내림차순 정렬 (in 우선순위 큐)
    }
};
priority_queue<Point, vector<Point>, cmp> pq;  // 자료형, 구현체, 비교연산자
int main(){
    pq.push({1, 1});
    pq.push({2, 2});
    pq.push({3, 3});
    pq.push({4, 4});
    pq.push({5, 5});
    pq.push({6, 6});
    cout << pq.top().x << "\n";
    return 0;
}
/* 6 */