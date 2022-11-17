// N의 범위: 2 ~ 10만
// K의 범위: 2 ~ (10만 - 1)
// 온도의 범위: -100 ~ 100
// 목표: 연속된 온도의 합이 "최대"가 되는 값을 구하라 => 구간합이 생각나야함! (psum[i] = psum[i-1] + a[i])

// 문제에서 최대값을 구하라하면 최소값부터 >>>> 최대값을 구해야함 (ret = max(ret, value))
// 문제에서 최소값을 구하라하면 최대값부터 >>>> 최소값을 구해야함 (ret = min(ret, value))
// 중요) 이 문제의 최솟값은? -100 * (10만번 - 1) >> 약 -1000만

// max(int a, int b): a, b중에 더 큰 수 반환
// min(int a, int b): a, b중에 더 작은 수 반환
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, temp, psum[100001];
int ret = -10000004 // 이 문제의 최소값 (끝점은 넉넉하게 잡아줌 (맞왜틀방지))
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> temp; psum[i] = psum[i - 1] + temp;
    }

    // !! 이 부분이 포인트임
    for(int i = k; i <= n; i++){
        ret = max(ret, psum[i] - psum[i - k]); // 연속적인 k일의 온도의 합 (최소값부터 최대값을 계속 갱신해나감)
    }
    cout << ret << "\n";
    return 0;
}