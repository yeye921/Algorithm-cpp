// 예제 -> 수식 -> 코드로 변환 
#include <bits/stdc++.h>
using namespace std; 
int n, m, j, l, r, temp, ret;
int main () {
	cin >> n >> m >> j; 
	l = 1;
	for(int i = 0; i < j; i++){
		r = l + m - 1;  // r = 바구니의 끝점
		cin >> temp;    // temp = 바구니의 위치
		if(temp >= l && temp <= r) continue; // 사과가 바구니 영역안으로 떨어지면 => 암것도 안함
		else{ 
			if(temp < l){  
				ret += (l - temp);
				l = temp;               // 어차피 r은 l을 따라서 수정되기 때문에 l만 처리하면 됨
			}else{
				l += (temp - r);
				ret += (temp - r); 
			}
		} 
	} 
	cout << ret << "\n"; 
	return 0;
}