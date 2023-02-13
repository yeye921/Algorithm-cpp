// 1 <= 집의 개수 < 2n
// m <= 치킨집의 개수 <= 13

// 폐업시키지 않을 치킨집을 "최대 M개" 골랐을 때, 도시의 치킨 거리의 최솟값을 출력
// 도시의 치킨집 중에서 최대 m개를 골라, 도시의 치킨 거리가 최소가 되게함

// 각각의 집은 집과 가장 가까운 치킨 집과의 거리인 치킨거리를 가짐
// 모든 집의 치킨 거리의 합 = 도시의 치킨 거리

// 비트마스킹으로도 할 수 있을듯
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, sum, ret=INF;
int _map[53][53];
vector<vector<int>> v;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
// 이거는 한 경우의 수에 대한 도시의 치킨거리임 ! 더 로직 필요함 !!
int go(vector<int> idx){
    // 여기서 도시의 치킨거리와 최소값 갱신 !
    // 각 집마다 가장 가까운 치킨집 찾음
    sum = 0;
    for(pair<int, int> pi : home){
        int sy = pi.first;
        int sx = pi.second;
        int city = INF; // 각 집의 최소 치킨거리 갱신


        // 한 경우에 대해서만 계산하면 됨
        // int ey = 888
        for(int i = 0; i < idx.size(); i++){ 
            int ey = chicken[i].first;
            int ex = chicken[i].second;
            cout << sy << " " << sx << " " << ey << " " << ex << "\n";
            int dist = abs(sy - ey) + abs(sx - ex);
            city = min(city, dist);    
        }
        sum += city;
    }
    cout << sum << "\n";
    return sum;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> _map[i][j];
            if(_map[i][j] == 1) home.push_back({i, j});
            else if(_map[i][j] == 2) chicken.push_back({i, j});
        }
    }
    // 디버깅
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << _map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    //     for(pair<int, int>pi : chicken){
    //     cout << "치킨 " << pi.first << " " << pi.second << "\n";
    // }
    //     for(pair<int, int>pi : home){
    //     cout << "집" << pi.first << " " << pi.second << "\n";
    // }
    // 최대 m개 뽑으면서 도시의 치킨 거리가 최소가 되게 함 (1~m개이면 상관없음)
    // m1) 조합 > combi
    // m2) 비트 마스킹 > 일단 이걸로 구현

    // 집의 위치들을 벡터에 담아두고 인덱스를 기반으로 뽑음
    for(int i = 1; i < (1 << m); i++){ // 최대 나올 수 있는 경우의 수 > 2^13 = 8192 
        vector<int> temp; 
        for(int j = 0; j < m; j++){
            if(i & (1 << j)){ // 각 경우의 수
                temp.push_back(j);
            }
        }
        v.push_back(temp); // 꿀팁) temp에 담고, v를 temp에 담기
        // 아니면 그냥 여기서 로직 돌려버리기
        ret = min(ret, go(temp)); // 
    }

    // 뽑은 치킨 집의 인덱스가 나옴
    // 뽑을 때 마다 도시의 치킨거리를 구해서 갱신해나가야함
    // for(vector<int> a : v){
    //     for(int i : a){
    //         cout << i << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ret << "\n";
    return 0;
}