// 커스텀 정렬을 따로 떼어서 구현하는 방법
#include <bits/stdc++.h>
using namespace std;
struct Point{
    int y, x;
};
bool cmp(const Point &a, const Point &b){ // a = first, b = last
    return a.x > b.x;  // a.x > b.x이면 그대로, a.x < b.x이면 둘의 순서 바꿈 (즉, x를 기준으로 내림차순 정렬)
}
vector<Point> v;
int main(){
    for(int i = 10; i >= 1; i--){
        v.push_back({i, 10 - i}); // v = {{10, 0}, {9, 1}, ..{1, 9}} // {y, x} 형태로 들어감

        // 아래 두 줄로 대체 가능
        // Point a = {i, 10 - i};
        // v.push_back(a);
    }
    sort(v.begin(), v.end(), cmp); // first = v.begin(), last = v.end(), cmp[first, last) 형태임 
    for(auto it : v) cout << it.y << " : " << it.x << "\n";
    return 0;
}