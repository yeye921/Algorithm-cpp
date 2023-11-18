// 회의실 배정 문제 > 그림을 그려보는 것이 좋다
// 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수 찾기
// 시작, 끝, 회의시간이 있다 > 끝으로 정렬해서 푸는 문제

// 1. 끝나는 시간을 기준으로 오름차순으로 정렬
// 2. 제일 일찍 끝나는 시간을 첫 회의로 설정
// 3. 반복문을 돌면서 from과 to를 갱신함
#include <bits/stdc++.h>
using namespace std;
int n, from, to, ret = 1;
int main(){
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({to, from}); // 끝으로 정렬해야하기 때문에 from와 to의 순서를 바꿈 > 이렇게하면 custom sort를 이용하지 않고도 두번째인자를 기준으로 정렬할 수 있음
    }

    sort(v.begin(), v.end()); // 1
    from = v[0].second; // 2
    to = v[0].first;

    for(int i = 1; i < n; i++){ // 3
        if(v[i].second < to) continue; // 다음 시작 시간이 이전 끝나는 시간보다 작으면 X
        from = v[i].second;
        to = v[i].first;
        ret++;
    }
    cout << ret;
    return 0;
}