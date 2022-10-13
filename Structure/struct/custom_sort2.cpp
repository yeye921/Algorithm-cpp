// y, x, z라는 속성이 존재
// x를 1순위로 오름차순 정렬, y를 2순위로 내림차순, z를 3순위로 오름차순 정렬
#include <bits/stdc++.h>
using namespace std;
struct Point{   // 여기가 포인트! 
    int y, x, z;
    Point(int y, int x, int z) : y(y), x(x), z(z){}
    Point(){y = -1; x = -1; z = -1;}
    bool operator < (const Point &a) const{
        if(x == a.x){
            if(y == a.y) return z < a.z;
            return y > a.y;
        }
        return x < a.x;
    }
};
vector<Point> v;
int main(){
    for(int i = 10; i >= 1; i--){
        Point a = {5, 5, i}; // y, x, z순으로 들어감
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(auto it : v) cout << it.y << " : " << it.x << " : " << it.z << "\n";
    return 0;
}