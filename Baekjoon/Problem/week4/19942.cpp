// 큰돌 풀이
#include<bits/stdc++.h>
using namespace std;  
typedef long long ll; 
const int INF = 987654321; // 최소값은 항상 최대값부터
int n, mp, mf, ms, mv;
int b, c, d, e, ret = INF, sum;
struct A{ // 5개를 입력받아야하니 pair이런걸로 안되고 간단한 struct를 정의해야함
	int mp, mf, ms, mv, cost; 
}a[16]; // 식재료 개수 N의 최대 값은 15
// vector<vector<int>>는 vector<int>가 여러개 있는 벡터를 뜻한다 !
map<int, vector<vector<int>>> ret_v; // costSum(총 비용)과 뽑은 영양소 idx를 매핑하기 위한 것 !!
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; 
    cin >> mp >> mf >> ms >> mv;  
    for(int i = 0; i < n; i++){
    	cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;  
	}
	for(int i = 1; i < (1 << n); i++){ // 비트마스킹을 이용해 모든 경우의 수 따짐 (0은 어차피 안되니까 i = 1부터)
		b = c = d = e = sum = 0;
        vector<int> v; 
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){ // 비트마스킹을 이용해 포함되어 있는 비트의 idx 구함(=j)
                v.push_back(j + 1); // v에 뽑은 영양소들의 idx를 담음 !
				b += a[j].mp;
				c += a[j].mf;
				d += a[j].ms;
				e += a[j].mv;
				sum += a[j].cost;
			}
		}
		if(b >= mp && c >= mf && d >= ms && e >= mv){ // 영양소 최소 기준을 만족하면
			if(ret >= sum){ // 비용이 최소가 되면 갱신해야함
				ret = sum;
                ret_v[ret].push_back(v); // map<int, vector<vector<int>>> 형태는 다음과 같이 삽입함 !!
			}
		} 
	}  
	if(ret == INF) cout << -1 << '\n'; // 갱신이 안되었으면 만들 수 없다는 것
	else{
        sort(ret_v[ret].begin(), ret_v[ret].end()); // 비용이 같다면 오름차순으로 정렬
		cout << ret << "\n";
		for(int a : ret_v[ret][0]){
			cout << a << " ";
		} 
	}  
	return 0; 
}