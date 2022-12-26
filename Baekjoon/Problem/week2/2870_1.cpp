// 숫자로 푸는 잘못된 예
#include <bits/stdc++.h>
using namespace std;
typedef unsigned int long long ll;
int n;
string s;
vector<ll> v; // 숫자들을 담을 배열
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        // 초기화
        int cnt = 0;
        // 문자열 탐색
        for(int i = 0; i < s.size(); i++){
            // 문자가 숫자인지 확인
            if(isdigit(s[i])){ 
                if(i < s.size() - 1 && isdigit(s[i + 1])){ // 다음 문자도 숫자이면
                    cnt++;
                }
                else { // 다음 문자가 숫자가 아니면
                    if(cnt > 0){
                        string sub = s.substr(i - cnt, cnt + 1); // 숫자들 뽑아냄
                        // cout << "뽑아낸 숫자들 " << sub << "\n"; 
                        // int num = atoi(sub.c_str());
                        ll num = stoi(sub);
                        // cout << "숫자 " << num << "\n"; // for 디버깅
                        v.push_back(num);
                        cnt = 0; // 초기화
                    } else {
                        v.push_back(s[i] - '0');
                    }
                }
            }
        }
    }
    // 종이에서 찾은 숫자의 개수 = 출력 줄의 개수
    sort(v.begin(), v.end());
    for(ll i : v) cout << i << "\n";
}