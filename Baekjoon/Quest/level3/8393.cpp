// 1부터 n까지 합을 구하는 프로그램 작성
// m1) 반복문 이용하여 계산 => O(n)
// m2) 등차수열 공식 이용 => O(1)?
#include <bits/stdc++.h>
using namespace std;
int n, sum;
int main(){
    cin >> n;
    // m1
    for(int i = 1; i <= n; i++){
        sum += i;
    }

    // m2
    sum = n * (n + 1) / 2;
    cout << sum << "\n";
    return 0;
}