#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int basket[104];
// swap 함수 정의
void swap(int idx1, int idx2){
    int temp = basket[idx1];
    basket[idx1] = basket[idx2];
    basket[idx2] = temp;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        basket[i] = i;
    }
    // 기존 값을 저장할 temp에 기존 값을 저장한 후, a인덱스에다가 b인덱스 값을 대입한 후
    // b인덱스에 a인덱스의 기존 값인 temp를 대입한다
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        swap(a, b);
    }
    for(int i = 1; i <= n; i++) cout << basket[i] << " ";
    cout << "\n";
}