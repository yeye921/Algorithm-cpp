// 큰돌 풀이
// 이 문제의 시간복잡도: 10! (10*9*8*.... = 암기! 362만 > 모든 경우의 수를 구하는 완전탐색으로 풀어도 괜찮다 !) 
// => 따라서 이 문제는 완전탐색(모든 경우의 수를 탐색)하는 것이다

// 이 문제는 문자열을 기반으로 해야함
#include <bits/stdc++.h>
using namespace std;
int n, visited[10];
char a[20]; // 부등호들을 저장하는 배열
vector<string> ret;  
bool ok(char x, char y, char op){ 
	if(x < y && op == '<') return true; 
	if(x > y && op == '>') return true; 
	return false; 
}
// 이 함수 이해 잘 안감
// 완전탐색은 항상 인덱스를 기반으로 한다
// 부등호를 만족하면 숫자를 이어붙이면서, 숫자를 총 n+1개 뽑는 함수
void go(int idx, string num){
    cout << idx << " " << num << "\n";
	if(idx == n + 1){ // 기저사례: 뽑은개수(idx)가 부등호개수+1이면 종료
		ret.push_back(num); return;
	}
	for(int i = 0; i <= 9; i++){
		if(visited[i]) continue; // 조건(선택된 숫자는 모두 달라야 한다) 체크
		if(idx == 0 || ok(num[idx - 1], i + '0', a[idx - 1])){ // 주어진 부등호를 만족하는 수인지 확인 (백트래킹)
			visited[i] = 1;
			go(idx + 1, num + to_string(i)); // 하나뽑았음으로 그거 처리하고 또 뽑으러감
			visited[i] = 0;
		}
	}
	return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> n; 
    for(int i = 0; i < n; i++) cin >> a[i]; // 부등호 입력받음
    go(0, "");
    sort(ret.begin(), ret.end()); // !! sort함수를 이용해서 string으로 이루어진 수 정렬가능함 (*min_element 함수도 가능함)
    cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
}