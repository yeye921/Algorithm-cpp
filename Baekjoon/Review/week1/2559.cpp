#include <bits/stdc++.h>
using namespace std;
int n, k, temp, sum;
vector<int> psum(100004); // psum을 배열이 아닌 벡터로 선언해도 가능
int ret = -10000004;
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }

    // 연속적인 k일의 온도의 합이 최대가 되는 값을 구하기!
    for(int i = k; i <= n; i++){
        sum = psum[i] - psum[i - k]; // 연속적인 k일의 온도의 합
        ret = max(ret, sum);
    }
    cout << ret << "\n";
    return 0;
}