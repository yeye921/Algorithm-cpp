// 종류는 필요하지만 이름까지는 필요없다 (종류에 해당하는 카운팅만 필요)
// head: 2, eye: 1을 기반으로 어떻게 해야 5가 나올까를 생각하면 됨

// 경우의 수는 곱하기다!
// !! 로직: 각각의 종류에 그 종류를 안입는 경우의 수를 추가해서 곱한 다음, 1을(아무것도 안입는 경우의 수) 빼주면 됨!
// ex, head: 2+1, eye: 1+1, 답: 3*2-1 = 5

// map요소 출력하는 법: for(auto it : mp) cout << it.first
// map요소 초기화: mp.clear()
// map의 find함수: mp.find("abc") -> second
#include <bits/stdc++.h>
using namespace std;
int t, n;
string a, b;
int main(){
    cin >> t;
    while(t--){
        map<string, int> _map;
        cin >> n;

        // 각 타입의 개수 저장
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            _map[b]++;
        }

        long long ret = 1; // 경우의 수는 수가 커질 수 있으니 long long으로 선언하기!
        // map을 순회하면서 경우의 수 구함
        for(auto element : _map){
            ret *= ((long long)element.second + 1); // !! 각 종류에 1을 더한다음 곱함 (ex. (a+1)*(b+1)*...)
        }                                           // 즉, 각 종류를 안입는 경우를 추가하는 것임
        ret--; // 모든 종류의 옷을 안입는 경우(=1가지)를 빼줌
        cout << ret << "\n";
    }
}