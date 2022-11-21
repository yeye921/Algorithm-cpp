// 목표: 주어진 알파벳들로 펠린드롬 만들기! (사전순으로 앞서게)
// 1. 주어진 각 알파벳 개수 세기
// 2. 주어진 알파벳들로 펠린드롬 만들기

// 펠린드롬이 불가능한 경우 => 홀수가 2개 이상일 때 ex. ABAC, ABCA

// 이해가 안가면
// 작게작게 여러개 예제만들어보면서 불가능한 경우 찾아보기

// 홀수 판단법: (n%2 == 1) 또는 if(n & 1)
// 홀수는 이진수로 표현하면 항상 1로 끝남
#include<bits/stdc++.h> 
using namespace std; 
string s, ret; 
int cnt[200], flag; 
char mid;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for(char a : s)cnt[a]++; // 카운팅 배열로 문자를 카운팅 함 (=알파벳 개수 저장)

    // 갖고있는 알파벳들로 사전순으로 앞서는 펠린드롬 만드는 로직!
	for(int i = 'Z'; i >= 'A'; i--){ // 아스키 코드상으로 가장 위에 있는 것부터 붙임 (for 사전순으로 앞서게)
		if(cnt[i]){
			if(cnt[i] & 1){ // 알파벳이 홀수개이면
				mid = char(i); // ! 홀수가 1개 들어오는 경우에 대한 처리 => 중앙에 넣음
                flag++;
				cnt[i]--; // for a가 3개일 경우 ..?
			}
			if(flag == 2)break; // !! 홀수개가 2개 이상이면 => 펠린드롬 불가능
            
            // 알파벳 앞뒤로 붙이는 로직
			for(int j = 0; j < cnt[i]; j += 2){
                // 아래를 수행하면 알파벳 2개를 소모하게 되니까 2개씩 증가(+=2)
				ret = char(i) + ret; 
				ret += char(i);
			}
		}
	}
	if(mid)ret.insert(ret.begin() + ret.size() / 2, mid); // ! 중앙에다가 mid를 넣음
	if(flag == 2)cout << "I'm Sorry Hansoo\n"; // !! 불가능 출력
	else cout << ret << "\n"; 
}