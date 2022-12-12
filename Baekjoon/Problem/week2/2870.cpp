// 숫자들은 찾은 뒤 오름차순 정렬 (숫자 앞에 0은 생략가능)
// 글자를 살펴보다가 숫자가 나오는 경우에는 가능한 가장 큰 숫자를 찾아야 함 => HOW??
// (즉, 모든 숫자의 앞과 뒤에 문자가 있거나, 줄의 시작또는 끝이어야 한다)

// 문자가 숫자인지 확인하는 방법: isdigit() 숫자가 아니면 0반환
// 맞왜틀 반례: 2 > a123456789012345678901234567890b > c1d2e
// 결론: 100글자의 숫자를 int형이 담을 수 없다 !!!

// 문제에서 주어지는 범위를 잘 봐야함
// int형은 10^9이니까 10글자, long long형은 10^18이니까 19글자 => 이 문제는 숫자로는 풀 수 없다 !! => big int OR 문자열 이용!!
#include <bits/stdc++.h>
using namespace std;   
int n; 
vector<string> v; 
string s, ret;
void go(){
	while(true){ // 앞에 0이 없을 때 까지 지움
		if(ret.size() && ret.front() == '0') ret.erase(ret.begin()); // front를 참조할 때는 항상 size로 있는지 체크해야함
		else break;
	}
	if(ret.size() == 0) ret = "0"; // ret = "000"처럼 주어지는 경우
	v.push_back(ret);
	ret = "";  
}
// 커스텀 오퍼레이터
// 문자열을 기반으로 숫자처럼 정렬 => 아스키코드 이용 (암기!!)
bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b; // 2순위: 아스키코드로 비교 (왼쪽에서 부터 비교)
	return a.size() < b.size(); // 1순위: 사이즈비교
}
int main () {
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> s; 
	 	ret = "";
		for(int j = 0; j < s.size(); j++){
			if(s[j] < 65) ret += s[j]; // 아스키코드를 이용하여 각문자가 숫자인지 체크
			else if(ret.size()) go(); // 현재 문자가 숫자가 아니고 ret이 존재하면 go()진행
		}
		if(ret.size()) go(); // 숫자가 문자열 끝까지 위치할 경우 => go처리 필요
	}
	sort(v.begin(), v.end(), cmp);
	for(string i : v)cout << i << "\n"; 
	return 0;
}