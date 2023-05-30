// m0) 문자열 이용 => 안됨. 문자열로 처리하면 
// m2) deque 이용 => 제일 best일듯 => 시간초과남..... 
// 계속 실수하는 것!!) 테케문에서 사용하는 벡터나 배열은 초기화가 필수다!!
#include <bits/stdc++.h>
using namespace std;
int T, n;
string func;
string arr;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int tc = 1; tc <= T; tc++){ // 테스트 케이스 문
        // 중요!) 테케문 초기화
        int cnt = 0;
        bool flag = 1;
        deque<int> dq;
        string ans;

        cin >> func;
        cin >> n; // 숫자의 개수
        cin >> arr;

        // []을 자름 (앞뒤로 1개)
        arr = arr.substr(1, arr.size() - 2);
        // ,를 기준으로 split (split 함수써도 되지만 여기선 간단히함)
        string num;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == ',') {
                dq.push_back(stoi(num)); // 정수로 변환해서 집어넣음
                num = "";
            }
            else {
                num += arr[i]; // 정수 문자열 붙임
            }
        }
        if(num.length()) dq.push_back(stoi(num)); // 배열의 마지막 숫자


        for(int i = 0; i < func.size(); i++){
            if(func[i] == 'R') cnt++;
            else {
                if(dq.size()){
                    cnt %= 2; // (cnt%2)번만큼 뒤집기 (무조건 0또는 1, 1번 뒤집거나 5번 뒤집거나 결과는 동일함)
                    if(cnt) {
                        reverse(dq.begin(), dq.end());
                        cnt = 0; // 초기화
                    }
                    // 배열의 첫번째 수 버림
                    dq.pop_front();
                }
                else {
                    // 에러 발생
                    flag = 0;
                    break;
                }
            }
        }
        if(!flag) cout << "error\n";
        else {
            // 덱에 담긴 숫자들을 [42, 19, ..]형태로 출력하는 법
            ans = '[' + ans;
            for(int i = 0; i < dq.size(); i++){
                ans += to_string(dq[i]); // 정수를 문자열로 변환해준뒤에 합쳐야 함
                if(i != dq.size()-1) ans += ',';
            }
            ans += ']';
            cout << ans << "\n";
        }
    }
}