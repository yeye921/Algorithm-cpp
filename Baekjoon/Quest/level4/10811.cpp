// m1) reverse 함수 이용 (배열, 벡터, 문자열 등의 요소들을 거꾸로 뒤집는 함수)
// m2) swap 함수 이용 (두 수의 값을 바꾸는 함수. temp를 통해 직접구현해도 됨)
#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
// vector<int> basket; // 배열과 벡터 모두 사용가능
int basket[104];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        basket[i] = i + 1; 
        // basket.push_back(i + 1);
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--; // 인덱스 맞춰줌
        // a부터 b번째 바구니의 순서를 역순으로 만든다
        // reverse(basket.begin() + a, basket.begin() + b + 1);
        reverse(basket + a, basket + b + 1);

        /* 
        m2) swap 방식 
        for(int i = 0; i <= (b - a) / 2; i++) {
			swap(basket[a + i], basket[b - i]);
		}
        */
    }
    for(int i = 0; i < n; i++){
        cout << basket[i] << " "; 
    }
    cout << "\n";
}