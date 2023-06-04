// 큰돌 풀이
// m2) 스택만을 이용한 풀이
#include <bits/stdc++.h>
using namespace std;
int n, cnt, ret;
string str;
stack<int> s;
int main() {
  cin >> n;
  cin >> str; 
  s.push(-1); // i에서 s.top을 빼서 길이를 세팅하는 로직을 위해서 처음을 -1로 설정한 것임

  for (int i = 0; i < n; i++) {
    if(str[i] == '(') s.push(i); // 괄호의 배열 내 인덱스를 집어넣음
    if(str[i] == ')') {
      s.pop();
      
      if(!s.empty()) {
      	ret = max(ret, i - s.top()); // 이 부분이 조금 어려움 (올바른 문자열의 가장 긴 길이로 세팅)
	  } else { 
	  	s.push(i); // 그 다음 분기점을 만들기위해서 설정하는 것
	  } 
  	}
  }
  cout << ret << '\n';
  return 0;
}  