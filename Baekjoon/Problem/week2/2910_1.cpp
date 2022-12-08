#include <bits/stdc++.h>
using namespace std;
int n, c, num;
vector<pair<int, int>> v; // {빈도, num} 저장
map<int, int> mp; // {num, 빈도} 저장
map<int, int> mp_first; // {num, 인덱스} 저장
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return mp_first[a.second] < mp_first[b.second]; // 2순위 인덱스 오름차순 정렬
    }
    return a.first > b.first; // 1순위 빈도수 내림차순 정렬
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> num;
        mp[num]++;
        if(mp_first[num] == 0){ // mp_first에 존재하지 않는다면
            mp_first[num] = i + 1;
        }
    }
    for(auto it : mp){
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), cmp);
    // 정렬된 v를 출력형식에 맞게 출력
    for(auto it : v){
        for(int i = 0; i < it.first; i++){
            cout << it.second << " ";
        }
    }
    return 0;
}