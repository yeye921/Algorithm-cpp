// 엄청 큰 수를 더하는 문제
// 인덱스를 뒤부터 매겨야 각 자리수끼리 더할 수 있음 => reverse 함수 이용하자

// min기준으로 탐색하면 반복문 2번 돌아야 함
// max기준으로 탐색하면 반복문 1번 돌아야 함

// 푸는데 1시간 30분 걸림...
#include <bits/stdc++.h>
using namespace std;
string a, b, ans;
int main(){
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // 둘 중 더 큰 자리수를 기준으로 탐색
    int mx = max(a.length(), b.length());
    int mn = min(a.length(), b.length());
    bool flag = 0;
    int sm = 0;
    for(int i = 0; i < mx; i++){
        // 여기서부터는 a,b 둘 중 더 큰 수만 가지고 더해야함 (안그럼 index 초과)
        if(i >= mn){
            if(a.size() > b.size()){
                sm = (a[i] - '0');
            }
            else if(a.size() < b.size()){
                sm = (b[i] - '0');
            }
        }
        else {
            sm = (a[i]-'0') + (b[i]-'0'); // 문자를 정수로 변환
        }
        if(flag) {
            sm += 1;
            flag = 0;
        }
        if(sm >= 10) {
            // 여기서 to_string을 하는게 맞는지 아니면 '0'을 더해주는게 맞는지..? => 둘 다 가능!!
            ans += (sm - 10 +'0'); // 10을 뺀 나머지 자리 수를 더해줌
            // 다음 자리수에 1을 더해줘야함 (즉, 올림처리)
            flag = 1;
          
        }
        else ans += to_string(sm);
    }
    if(flag){
        ans += '1'; // 제일 마지막 자리수에서 10이 넘으면 다음자리에 올림해줘야함
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}