// 자연수 N이 주어지면 "N!의 오른쪽 끝에 있는 0의 개수" 알려주기 ????
// => 오른쪽 끝에 있는 0의 개수가 도대체 무슨 뜻임???

// N!자체를 계산하기에는 시간복잡도가 너무 크다
// => N!을 계산하지 않고 그수의 오른쪽 끝에 있는 0의 개수를 구해야함

// 0은 10을 통해서 만들어지고 => 10은 2와 5를 통해서 만들어진다 (10 = 2 * 5)
// 즉, 이 문제는 N!의 2와 5의 개수를 구하는 문제다

// 나열을 하다보면 이해가 잘된다 (강의 그림 참고)
#include <bits/stdc++.h>
using namespace std; 
int t, n;
int main (){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL); // 이 코드없으면 시간초과남
	cin >> t; 
	for(int i = 0; i < t; i++){
		cin >> n; 
		int cnt2 = 0, cnt5 = 0; // 테스트케이스 문제는 초기화가 핵심이다 !!

		for(int j = 2; j <= n; j *= 2){ // n!에 포함된 2의 개수 세기
			cnt2 += n / j;  
		}

		for(int j = 5; j <= n; j *= 5){ // n!에 포함된 5의 개수 세기
			cnt5 += n / j; 
		}

		cout << min(cnt2, cnt5) << "\n"; // 둘 중 최소인 것을 찾아야 => n!에 포함된 10의 개수를 찾을 수 있음 !
    }
	return 0;
}