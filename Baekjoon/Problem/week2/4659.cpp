// 1. 모음 하나를 반드시 포함
// 2. 모음/자음이 3개 연속으로 오지 않음
// 3. 같은 글자가 연속으로 2번오면 안되나 ee와 oo는 허용

// 나의 반례는 bontres!! => 자음이 3개 연속으로 오고나서 모음이오면 
#include <bits/stdc++.h>
using namespace std;  
string s; 
int lcnt, vcnt; // 각각 모음과 자음의 연속되는 횟수 카운트
bool isVowel(int idx){ // 각 글자가 모음인지 확인
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}
int main () { 
	while(true){
		cin >> s; 
		if(s == "end")break; 

   		// 각 테스트케이스마다 호출되기 때문에 초기화가 중요!!
		lcnt = vcnt = 0;
		bool flag = 0;
		bool is_include_v = 0; // 모음이 하나라도 있는지 
		int prev = -1;

		// m1) 문자열을 탐색하는 방식
		for(int i = 0; i < s.size(); i++){
			int idx = s[i]; // idx = 알파벳
			if(isVowel(idx)){// 모음이라면 
                lcnt++, vcnt = 0, is_include_v = 1;
            }
			else vcnt++, lcnt = 0; // 자음이라면
			if(vcnt == 3 || lcnt == 3) flag = 1; // 모음또는 자음이 연속으로 3번 이상 나옴
            
            // 3번 조건 체크 => 스킬: prev라는 것을 사용하면 됨 !!
			if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')){ // prev는 0번째 이상이어야 비교 가능
				flag  = 1; // not acceptable 표시
			} 
			prev = idx; // 이전 값을 prev에 저장하여 현재 값과 비교
		}  
		if(is_include_v == 0) flag = 1;
		if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
	} 
	return 0;
}