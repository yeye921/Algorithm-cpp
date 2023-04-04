// 구매한 물건의 가격과 개수로 계산한 총 금액이 영수증에 적힌 총 금액과 일치하는지 검사
#include <bits/stdc++.h>
using namespace std;
// x의 범위가 1억까지임 > int로 처리 가능
int x, n, a, b, sum;
int main(){
    cin >> x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        sum += a * b;
    }
    if(x == sum) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}