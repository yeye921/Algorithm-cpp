// 커스텀 정렬을 따로 떼어서 구현하는 방법
#include <bits/stdc++.h>
using namespace std;
struct Point{
    int y, x;
};
bool cmp(const Point &a, const Point &b){ // first, last
    return a.x > b.x;  // a.x > b.x이면 그대로, a.x < b.x이면 둘의 순서 바꿈 (즉, x를 기준으로 내림차순 정렬)
}
vector<Point> v;
int main(){
    for(int i = 10; i >= 1; i--){
        v.push_back({i, 10 - i}); // v = {{10, 0}, {9, 1}, ..{1, 9}} // {y, x} 형태로 들어감
    }
    sort(v.begin(), v.end(), cmp); // first = v.begin(), last = v.end(), cmp[first, last) 형태임 
    for(auto it : v) cout << it.x << " : " << it.y << "\n";
    return 0;
}