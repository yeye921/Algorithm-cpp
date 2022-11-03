// 구조체 자체내에 커스텀 정렬 구현하는 방법
// 1순위로 x를 기준으로 오름차순 정렬, 2순위로 y를 기준으로 오름차순 정렬
// 다시 복습하기!!
#include <bits/stdc++.h>
using namespace std;
struct Point {
    int y, x;
    Point(int y, int x) : y(y), x(x) {}  // y가 x보다 먼저나오는 이유가 뭐지?
    Point(){y = -1; x = -1; }
    bool operator < (const Point & a) const { // a = last
        if(x == a.x) return y < a.y;  // y를 기준으로 오름차순 정렬
        return x < a.x;  // x < a.x이면 그대로, x > a.x이면 둘의 순서 바꿈
                         // 즉, x를 기준으로 오름차순 정렬
    }
};
vector<Point> v;
int main(){
    for(int i = 10; i >= 1; i--){
        Point a = {i, i};  // a = {10, 10}, {9, 9}, ..., {1, 1}
        v.push_back(a);
    }
    sort(v.begin(), v.end());  // cmp 생략
    for(auto it : v) cout << it.y << " : " << it.x << "\n";
    return 0;
}