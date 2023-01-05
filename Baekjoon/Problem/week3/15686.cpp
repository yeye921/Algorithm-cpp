// 이전 문제와 유사한듯..?

// 핵심 알고리즘
// 1. 치킨집 중 m개 뽑기 => 모든 경우의 수에대해 탐색
// 2. 그 경우의 수에 대해 집마다 치킨거리 계산
// 3. 모든 경우의 수에 대해 도시의 치킨 거리가 가장 작게 되는 경우 출력

// 어떤 문제든 처음 보면 무식하게 풀 수 있는가를 생각하고 > 시간 복잡도를 계산 > 괜찮으면 무식하게 품
// 안괜찮으면 알고리즘 적용해서 품

// But, 제외 조건 존재: 집의 최대 개수 2n(=100), 치킨집의 최대 개수 = 13
// 즉, 올바른 시간복잡도는 13 C ? * 100 = 대략 1716 * 100 => 17만, 무식하게 풀 수 있다 !!

// +) combination은 중앙으로 갈수록 큰 값을 갖는다
// n C r = n C n-r
// 13 C 6 = 1716

// 조합을 코드로 구현하는 방법 (인덱스를 기반으로 뽑음)
// 1. 재귀함수 이용 => 가능
// 2. 중첩 for문 이용 => r을 몰라서 할 수 없음, 불가능

// 배열의 가장 작은 값 찾는 법: *min_element(v.begin(), v.end()); (인덱스도 구할 수 있음)
// 절댓값 구하는 함수: int abs(int num)
#include <bits/stdc++.h>
using namespace std;
int n, m, a[53][53];
vector<pair<int, int>> chk_list, hm_list;
vector<int> city_dists; // 도시의 치킨거리 중 최소가 되는 것 구함
void countDist(vector<int> v){
    // 집마다 탐색하며 치킨거리 계산
    // 각 경우의 수에 대해 계산하므로 초기화가 중요!!
    int city_dist = 0;
    for(auto hm : hm_list){
        vector<int> chk_dists;
        for(int i : v){
            int dist = abs(hm.first - chk_list[i].first) + abs(hm.second - chk_list[i].second);
            chk_dists.push_back(dist);
        }
        // 각 집마다 치킨 거리 구해서 도시의 치킨 거리에 더해줌
        city_dist += *min_element(chk_dists.begin(), chk_dists.end());
    }
    city_dists.push_back(city_dist);
}
void combi(int start, vector<int> v){
    if(v.size() == m){ // 기저사례 (m개 다 뽑음)
        countDist(v);
        return;
    }
    for(int i = start + 1; i < chk_list.size(); i++){ // 인덱스 기반으로 뽑음
        v.push_back(i); 
        combi(i, v);
        v.pop_back(); // 완탐해제
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) chk_list.push_back({i, j});
            if(a[i][j] == 1) hm_list.push_back({i, j});
        }
    }
    // 치킨집 중에서 m개 뽑기 => 재귀함수 이용
    vector<int> v;
    combi(-1, v);
    cout << *min_element(city_dists.begin(), city_dists.end()) << "\n"; 
}