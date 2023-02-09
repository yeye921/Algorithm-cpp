// 시간복잡도 계산하는 방식이 이해가 안감 !!! (행만 하는거)
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
string s;
int n, ret=INF;
int a[23];
// 핵심로직: 행 뒤집는 것에 대하여 완전탐색 진행 후, 열 뒤집는게 나을지 판단하는 로직
void go(int row){ // 행의 숫자를 전달받음
    if(row == n){  // 기저사례: 행의 끝까지 완탐 완료함
        // 행을 다 뒤집고 난 다음에 기저사례에서 열을 뒤집을지 결정
        int sum = 0;
        for(int i = 1; i <= (1 << (n - 1)); i *= 2){ // i = 1,2,4로 가야함 (각 자리가 켜져있는지 확인하기 위해)
            int cnt = 0;
            for(int j = 0; j < n; j++) if(a[j] & i) cnt++; // 각 행의 i열 탬색
            sum += min(cnt, n - cnt); // 해당 열을 뒤집는게 나은지 판단
        }
        ret = min(ret, sum); // 'T'의 개수가 가장 최소가 되는 개수를 구함
        return;
    }
    go(row + 1);
    a[row] = ~a[row]; // 해당 행을 뒤집음
    go(row + 1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    // 비트마스킹을 이용하여 동전들의 한 행을 하나의 숫자로 저장 > 배열 a이용
    for(int i = 0; i < n; i++){
        cin >> s;
        int val = 1;
        for(int j = 0; j < n; j++){
            if(s[j] == 'T') a[i] |= val; // 1행 HHT를 a[0] = 4로 저장하는 방식 (OR연산자 이용) 
            val *= 2;
        }
    }
    // for(int i = 0; i < n; i++) cout << a[i] << " "; // 4 1 5
    go(0);
    cout << "\n";
    cout << ret << "\n";
}