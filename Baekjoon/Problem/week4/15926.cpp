// 큰돌 풀이
// 올바른 괄호 문자열의 max 길이값을 출력하는 문제

// m1) 배열을 사용하는 방법 => 올바르면 1, 올바르지 않으면 0을 배열값으로 넣음
// ( ( ) ) ) ( ( ( ) ) ) ) 
// 1 1 1 1 0 1 1 1 1 1 1 0  이렇게 해서 max 1의 길이를 출력하는 문제
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int n, d[200001], ret, cnt; 
string s;
stack<int> stk;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cin >> n >> s;   
    // '('가 오면 무조건 push하고 스택에 몬가 있는 상태에서 ')'가 오면 pop하고
    // 최종적으로 스택이 비어있는 상태이면 올바른 문자열인 평소 로직을 응용한 풀이 
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') stk.push(i); // 중요) 스택에 괄호 문자열내 인덱스를 집어넣음
		else if(stk.size()){ 
				d[i] = d[stk.top()] = 1; // 올바른 괄호()를 배열에 1로 표기함 (즉, (())룰 1111로 배열에 표기험)
				stk.pop(); 
		}
        // 올바르지 않은 문자열에 대한 처리는 따로 해주지 않음 (초기값으로 이미 0으로 설정했기 때문)
	} 
	// 여기 부분이 은근 중요함 (이거때문에 계속 틀림!!)
    // 만든 배열을 순회하면서 가장 긴 연속된 1의 길이를 구함
	for(int i = 0; i < n; i++){
		if(d[i]) {
			cnt++;
            ret = max(ret, cnt);   // 이렇게 해주는게 중요
		} else cnt = 0;  
	}

	/* 위 방법 대신 이렇게 해도 되긴 함
	for(int i = 0; i < n; i++){
		if(d[i]){
			cnt++;
		}
		else {
			ret = max(ret, cnt);
			cnt = 0;
		}
	}
	if(cnt) ret = max(ret, cnt);
	*/
	cout << ret << "\n"; 
}