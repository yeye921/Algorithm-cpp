#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string, int> _map;
    _map["큰돌"]++; // 포인트
    _map["큰돌"]++;
    for(auto c : _map){
        cout << c.first << " : " << c.second << "\n";  // 큰돌 : 2
    }
    return 0;
}
// map의 경우 해당 인덱스에 참조만 해도, 맵에 값이 생기며 맵의 요소가 생긴다
// int형의 경우 0으로, string의 경우 빈문자열로 들어간다