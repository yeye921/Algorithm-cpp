#include <bits/stdc++.h>
using namespace std;
int n, m;
int i, j, k;
int arr[104];
int main(){
    cin >> n >> m;
    // 공을 넣는 방법
    for(int x = 0; x < m; x++){
        cin >> i >> j >> k;
        for(int idx = i; idx <= j; idx++){
            arr[idx] = k;
            // 해당 idx바구니에 k번 공을 넣는다
            // 바구니에 공이 이미 있는 경우, 들어 있는 공을 빼고 새로 공을 넣는다
        }
    }
    for(int i = 1; i <= n; i++){ // 인덱스를 0이 아니라 1부터로 맞춰줘야함
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}