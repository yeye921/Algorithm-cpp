// 모르겠는 것
// 벡터 요소 중 가장 큰 값 찾기: *max_element(first, last)
// 구간 합 구하는 방법 .. ?
#include <bits/stdc++.h>
using namespace std;
int N, K, temp, sum;
vector<int> v, ret;
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> temp;
        v.push_back(temp);
    }
    
    // 이 로직이 시간초과가 남!
    for(int i = 0; i < (N - K + 1); i++){ // 묶는 횟수
        sum = 0;
        for(int j = i; j < K + i; j++){ // 반복하는 횟수가 k번이어야 함
            sum += v[j];
        }
        ret.push_back(sum);
    }

    cout << *max_element(ret.begin(), ret.end());
    return 0;
}