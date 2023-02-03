// 내 풀이 > 큰돌 참고해서 맞음
// 최저 영양소 기준을 만족하는 최소 비용의 식재료 찾아야 함

// 조건을 만족하는 최소 비용 식재료의 번호를 공백으로 구분해 오름차순으로 출력
// 같은 비용의 집합이 하나 이상이면 사전 순으로 가장 빠른 것을 출력

// 최대 경우의 수는 2^15 = 1024 * 32 = 32768 
// 32768 * 15 = 491520 (시간복잡도는 49만)

// 나는 이런 자료구조랑 매핑문제에 취약한 듯
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, ret = INF;
int mp, mf, ms, mv;
int _mp, _mf, _ms, _mv;
int table[18][8];
vector<int> temp[32768];
map<int, vector<vector<int>>> _map;
int main(){
    cin >> n; // 식재료 개수
    cin >> mp >> mf >> ms >> mv; // 각 영양분이 이거 이상이어야 함
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            cin >> table[i][j];
        }
    }
    
    for(int i = 0; i < (1 << n); i++){ // 모든 경우의 수 탐색(64)
        for(int j = 0; j < n; j++){ // 한 경우의 수에서 켜져있는 비트들을 temp에 담음
            if(i & (1 << j)){
                temp[i].push_back(j); // i: 경우의 수, j: 뽑은 식재료의 번호 
            }
        }
    }

    for(int i = 0; i < (1 << n); i++){ // temp(=모든 경우의 수)를 탐색
        string s = "";
        vector<int> v;
        int cost = _mp = _mf = _ms = _mv = 0;
        for(int idx : temp[i]){ // idx: 포함되어있는 비트의 idx를 의미함 (ex. 1 = 1번재 비트가 포함되어있다)
            // 여기에 로직 들어감
            _mp += table[idx][0];
            _mf += table[idx][1];
            _ms += table[idx][2];
            _mv += table[idx][3];
            cost += table[idx][4];
            v.push_back(idx + 1);
        }
        if(_mp >= mp && _mf >= mf && _ms >= ms && _mv >= mv){ // 영양분이 기준을 만족하면
            if(ret >= cost){ // 최소비용 갱신
                ret = cost;
                _map[ret].push_back(v); // 같은 비용의 집합이 하나 이상일수도 있음 (그래서 vector<vector<int>>로 선언한 것!)
            }
        }
    }
    // map은 기본적으로 key값 기준 오름차순으로 정렬됨
    if(ret == INF) cout << -1 << "\n";
    else{
        cout << ret << "\n";
        sort(_map[ret].begin(), _map[ret].end()); // 최소 비용에 해당하는 집합이 하나 이상이면 사전순으로 가장 빠른 것 출력해야함
        for(int i : _map[ret][0]){
            cout << i << " ";
        }
        cout << "\n";
    }
    // map의 요소 탐색하는 법
    // for(auto iter = _map.begin(); iter != _map.end(); iter++){
    //     cout << iter -> first << "\n";
    // }
    return 0;
}