// pair 정렬에 커스텀 연산자 사용
// 내림차순 정렬하고 싶을 때 OR first는 내림차순, second는 오름차순 정렬하고 싶을 때
// 커스텀 연산자는 struct 설명할 때 자세히 배움
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first; // a의 첫번째 원소가 b의 첫번째 원소보다 크면 참 (뭔소린지 모르겠음)
}
int main(){
    for(int i = 10; i >= 1; i--){
        v.push_back({i, 10 - i});  // v = {{10, 0}, {9, 1}, ..., {1, 9}}
    }
    sort(v.begin(), v.end(), cmp); // 함수 인자가 전달이 안되는데 어떻게 되는거임?
    // for(auto it : v) cout << it.first << " : " << it.second << "\n";

    return 0;
}