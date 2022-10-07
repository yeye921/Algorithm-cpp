// pair 정렬에 커스텀 연산자 사용
// 내림차순 정렬하고 싶을 때 OR first는 내림차순, second는 오름차순 정렬하고 싶을 때
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
bool cmp (pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}
int main(){
    for(int i = 10; i >= 1; i--){
        v.push_back({i, 10 - i});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto it : v) cout << it.first << " : " << it.second << "\n";

    return 0;
}