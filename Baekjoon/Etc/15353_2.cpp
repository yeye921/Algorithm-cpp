// 큰돌 풀이
// 수 범위가 long long 보다도 크다 (int: 20억까지, long long: 20억*20억까지)
// string을 이용하는 방법과 BigInt라는 자료형을 만들어서하는 방법이 존재

// 로직
// 1. 큰수이기 때문에 string을 이용해서 할 생각
// 2. sum을 이용해서 올림을 처리
// 3. 올림을 처리하기 위해 reverse를 해서 끝에서 부터 더할 생각

// +) string에 back(), pop_back()함수를 적용할 수 있다
#include <bits/stdc++.h>
using namespace std;
string a, b, ans;
int main(){
    cin >> a >> b;
    int sum = 0;
    while(a.size() || b.size() || sum){ // sum은 올림을 의미함
        if(a.size()){
            sum += a.back() - '0'; // 숫자 문자열의 뒤에서부터 더함 (올림처리를 해주기위해)
            a.pop_back();
        }
        if(b.size()){
            sum += b.back() - '0';
            b.pop_back();
        }
        // 일의자리 수를 결과값에 누적
        ans += (sum % 10) + '0';  // ret에는 13의 경우 3을 담음 (ret에는 나머지를 담음)
        sum /= 10; // 올림이면, 다음 자리수에 올림을 반영 (sum을 올림값(0또는 1)로 초기화함)
    }
    reverse(ans.begin(), ans.end()); // 뒤에서부터 더했기 때문에 다시 뒤집어줘야함
    cout << ans << "\n";
}