// vector에 치킨집 좌표들 넣어 놓고 combi를 이용해서 인덱스 기반으로 뽑을 것임
// ex. idx = 0, 1, 2 => {1, 1}, {1, 5}, {2, 5}

// 최악의 시간복잡도 계산은 포기하지 않고 꾸준히 하면 할 수 있음 !!
#include <bits/stdc++.h>
using namespace std;
int n, m, a[54][54], result = 987654321;
// 중첩 벡터, 2차원 벡터 (벡터안에 벡터가 존재)
// {{0,1,2}, {0,1,3},..} 이런식으로 조합들을 저장하기 위해 사용
vector<vector<int>>chickenList;
vector<pair<int, int>> _home, chicken;
void combi(int start, vector<int> v){
    if(v.size() == m){
        chickenList.push_back(v); // 포인트, ex. 치킨리스트에 {1,2,3}을 넣음
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1)_home.push_back({i, j});
            if(a[i][j] == 2)chicken.push_back({i, j});
        }
    }
    vector<int> v;
    combi(-1, v);
    // 2차원 배열에 담긴, 각 경우의 수 탐색 (m개 뽑는 경우의 수 여러 개 들어있음)
    for(vector<int> cList : chickenList){ // 각 경우의 수 마다 도시의 치킨거리가 나옴 =>  그 중 최소찾기
        int ret = 0;
        for(pair<int, int> home : _home){
            int _min = 987654321; // 최소값은 최대값 부터 !!
            // 치킨집을 뽑아서 집과 거리 비교
            for(int ch : cList){
                int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
                _min = min(_min, _dist); // 각 집에서 가장 가까운 치킨집 (즉, 치킨거리)
            }
            ret += _min;
        }
        result = min(result, ret); // 최소가 되는 "도시의 치킨거리" 업데이트
    }
    cout << result << "\n";
    return 0;
}
