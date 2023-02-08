// 큰돌 풀이
// 4주차에서 가장 어려운 문제 (난이도 높은 문제들은 이런식으로 시간복잡도를 줄여야하는 문제들이다!)
// 이 문제의 시간복잡도는 2^40 (=2^(행20+ 열20)) > 어떻게 하면 여기서 시간 복잡도를 줄일 수 있을까?

// 핵심 로직
// 1. 행만 뒤집음
// 2. 열들을 탐색하며 T가 많으면 뒤집고 아니면 안뒤집음
// 따라서 행만 뒤집어도 되므로 시간 복잡도가 2^20이다
// (행만 뒤집으면 열의 최적해는 정해져있다)

// 비트마스킹: 불리언 배열(ex. 101)을 하나의 숫자 값으로 나타내는 것
// +) 비트마스킹은 30까지의 경우의 수만 표현할 수 있음, 이 문제는 n=20이라 적용가능
// HHT = 4, HTT = 6(=2+4)으로 표현함

// 주의: 101을 뒤집으면 010이 아니라 1111111...010이 되는 것임!
// 따라서 ~a = -(a + 1)이라는 것을 기억하기 !!
// 여기서는 동전을 뒤집는 것이기 때문에 그 앞비트까지 고려할 필요는 없음 
#include<bits/stdc++.h>
#define maxn 200005
typedef long long ll;
using namespace std;   
const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1}; 
int n, a[44], ret = INF;
string s; 
void go(int here){
	if(here == n + 1){ // 기저사례: 행 끝까지 탐색하면 종료
		int sum = 0; 
        // 열을 뒤집는게 나은지 판단하는 로직 !!
		for(int i = 1; i <= (1 << (n - 1)); i *= 2){ // (열을 기준으로 탐색 !!) 1,2,4열만 체크하면 됨
			int cnt = 0; 
			for(int j = 1; j <= n; j++) if(a[j] & i)cnt++; // j열에 켜져있는 비트 개수(=cnt) 계산 (ex. 1열 HTT = 1*2 = 2, 2열 THT = 2*2 = 4)
			sum += min(cnt, n - cnt); // 한 열의 원래 값과 뒤집었을 때의 값(n-cnt)을 비교해서 어떤게 더 적은 것을 더함
		}
		ret = min(ret, sum); // 전체 1의 개수 갱신
		return;
	}
	go(here + 1); // 안뒤집고
	a[here] = ~a[here]; // ~연산 이용해서 뒤집음
	go(here + 1); // 뒤집음 적용됨
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    // 한 행마다 비트마스킹해서 a[i]에 저장함
	for(int i = 1; i <= n; i++){
		cin >> s; // 문자열 입력
		int value = 1; 
		for(int j = 0; j < s.size(); j++){ // 행렬 a는 0으로 초기화되어 있음
			if(s[j] == 'T') a[i] |= value; // (중요!! 각 자리수마다 1,2,4,..곱함) HHT = 4, HTT = 6(=2+4)으로 표현함 (문자열을 하나의 숫자로 표현함)
			value *= 2; // value가 1,2,4,8,.. 로 증가함
		}
	}   
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
	go(1); // 행렬 a의 1부터 시작했기 때문에 go도 1부터 시작함
	cout << ret << "\n";
    return 0;
}
/*
HHT
THH
THT
4 1 5 (비트마스킹)
*/