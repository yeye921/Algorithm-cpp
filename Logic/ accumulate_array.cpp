// 정적 배열 => 누적합 이용
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100004], b, c, psum[100004], n, m;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i]; // 입력받으면서 누적합 저장함
    }
    for(int i = 0; i < m; i++){
        cin >> b >> c;
        cout << psum[c] - psum[b - 1] << "\n";
    }
    return 0;
}