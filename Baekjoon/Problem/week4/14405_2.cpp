// 큰돌 풀이
// substr을 이용한 풀이
#include<bits/stdc++.h>   
using namespace std;   
typedef long long ll;   
string s; 
bool flag = 0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s; 
    // 입력받은 문자열 순회 (글자수만큼 인덱스를 증가시켜야함)
	for(int i = 0; i < s.size(); i++){ 
        // 해당 인덱스부터 2자리 글자로 잘랐을 때 일치하는지 확인 (일치하면 인덱스 +1)
		if(i < s.size() - 1 && s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka") i += 1;

        // 해당 인덱스부터 3자리 글자로 잘랐을 때 일치하는지 확인 (일치하면 인덱스 +2) 
		else if(i < s.size() - 2 && s.substr(i, 3) == "chu") i += 2;

        // "pi", "ka", "chu"와 일치하는 것이 없을 경우 NO
		else flag = 1; 
	}
	if(flag) cout << "NO\n";
	else cout << "YES\n"; 
    return 0;
} 