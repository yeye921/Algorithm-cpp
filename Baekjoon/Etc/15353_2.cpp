// 큰돌 풀이
// 수 범위가 long long 보다도 크다 (int: 20억까지, long long: 20억*20억까지)
// string을 이용하는 방법과 BigInt라는 자료형을 만들어서하는 방법이 존재

// 로직
// 1. 큰수이기 때문에 string을 이용해서 할 생각
// 2. sum을 이용해서 올림을 처리
// 3. 올림을 처리하기 위해 reverse를 해서 끝에서 부터 더할 생각

// +) string에 back(), pop_back()함수를 적용할 수 있다
#include<bits/stdc++.h>
using namespace std;   
string string_add(string a, string b) {
    int sum = 0;
	string ret; 
    while(a.size() || b.size() || sum){ // sum은 올림을 의미함
        if(a.size()) {
            sum += a.back() - '0'; // 문자를 정수로 변환
            a.pop_back(); // 문자열의 가장 뒤에 있는 문자 꺼냄
        }
        if(b.size()) {
            sum += b.back() - '0';
            b.pop_back(); 
        }
        ret += (sum % 10) + '0'; // ret에는 13의 경우 3을 담음 (ret에는 나머지를 담음)
        sum /= 10; // sum은 올림이기때문에 0또는 1이 되어야함
    }
	reverse(ret.begin(), ret.end());
	return ret;
} 
string a, b; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);   
    cin >> a >> b;  
    cout << string_add(a, b) << '\n'; 
    return 0; 
}