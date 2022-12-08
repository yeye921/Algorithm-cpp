// 등장하는 횟수가 큰 순으로 정렬해야함
// 만약 횟수가 같은 것들이 있다면 수열에서 먼저 나온 것이 앞에 있어야 한다 => 이게 제일 어려움

// map과 set은 자동으로 정렬된다 (디폴트는 오름차순 정렬)
// map의 first는 key이고, second는 value이다

// 이 문제는 커스텀 오퍼레이터가 생각나야함! => 벡터나 배열은 sort함수를 통해 정렬 가능함
// 1순위 counting, 2순위 먼저나온순으로 정렬!
// 모르겠으면 Study > Structure > struct 복습
#include <bits/stdc++.h>
using namespace std;  
int n, c, num;
vector<pair<int, int>> v; // {빈도, num} 
map<int, int> mp;         // {num, 빈도}
map<int, int> mp_first;   // {num, 인덱스}

// 커스텀 오퍼레이터
bool cmp(pair<int,int> a, pair<int, int> b){
	if(a.first == b.first){ // 카운팅이 같다면
		return mp_first[a.second] < mp_first[b.second]; // 2순위: 인덱스 오름차순 정렬
	}
	return a.first > b.first; // 1순위: 빈도수 내림차순 정렬
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c; 

	for(int i = 0; i < n; i++){
		cin >> num;
        mp[num]++; // mp은 카운팅 배열처럼 사용
		if(mp_first[num] == 0){ // mp_first는 인덱스 저장
            mp_first[num] = i + 1;  // 맵에 요소가 없는지 확인하고 할당하는 로직 (0이면 없는거니까 i대신 i + 1 할당) 
            cout << num << " : " << mp_first[num] << "\n"; 
        }
    }
	for(auto it : mp){
		v.push_back({it.second, it.first});
	}

	sort(v.begin(), v.end(), cmp); // sort의 커스텀오퍼레이터 사용하여 정렬 (빈도순 > 먼저나온순)
    // 정렬된 v를 출력형식에 맞게 출력
	for(auto i : v){
		for(int j = 0; j < i.first; j++){
			cout << i.second << " ";
		}
	}  
	return 0;
}
