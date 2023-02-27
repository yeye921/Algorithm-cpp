// 최저 영양소 기준을 만족하는 최소 비용의 식재료 집합을 찾아야 함
// 구조체에 대한 공부 필요
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, mp, mf, ms, mv, cost;
int _mp, _mf, _ms, _mv, _cost, ret=INF;
struct A{
    int mp, mf, ms, mv, cost;
}a[16];
map<int, vector<vector<int>>> _map; // 한 비용에 여러 개의 인덱스 집합이 들어갈 수 있음
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;  
    for(int i = 0; i < n; i++){
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
    }

    // 뽑기
    for(int i = 0; i < (1 << n); i++){
        vector<int> temp;
        _mp = _mf = _ms = _mv = _cost = 0;
        for(int j = 0; j < n; j++){ // 각 경우의 수마다 뽑는 식재료에 대한 처리 > 로직 나옴
            if(i & (1 << j)){
                _mp += a[j].mp;
                _mf += a[j].mf;
                _ms += a[j].ms;
                _mv += a[j].mv;
                _cost += a[j].cost;
                temp.push_back(j + 1);
            }
            if(_mp >= mp && _mf >= mf && _ms >= ms && _mv >= mv){
                if(ret > _cost){ // 최소 비용 업데이트
                    ret = _cost;
                    _map[ret].push_back(temp);  // 비용 <-> 뽑은 영양소 번호를 매핑할 map(key - value쌍)이 필요함 !! (중요) 
                } 
            }
        }
    }
    if(ret == INF) cout << -1 << "\n";
    else {
        cout << ret << "\n";
        sort(_map[ret].begin(), _map[ret].end()); // 여기도 중요 !! _map의 최소 비용의 집합이 하나 이상아면 사전 순으로 정렬
        for(int i : _map[ret][0]){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}