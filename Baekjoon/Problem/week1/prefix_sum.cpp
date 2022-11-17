// 포인트: 1 <= a <= b <= N
// 목표: a번째부터 b번째까지의 합
#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, psum[100004], num; // 배열 범위는 항상 넉넉하게!
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> num;
        psum[i] = psum[i - 1] + num;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cout << psum[b] - psum[a - 1] << "\n";
    }
    return 0;
}