// 큰돌 코드 (굳이 왜 이렇게 구현해야하는지 모르겠음)
// 후위증가: a = cnt++; (대입 후 증가)
// 전위증가: a = ++cnt; (증가 후 대입) 
#include <bits/stdc++.h>
using namespace std;  
int n, m, a[104][104];
string s; 
int main () {
	cin >> n >> m; 
	for(int i = 0; i < n; i++){
		cin >> s; 
		for(int j = 0; j < m; j++){ // 다음과 같이 초기화
			if(s[j] == '.')a[i][j] = -1; // 구름이 없는 위치 => -1
			else a[i][j] = 0;            // 구름이 있는 위치 => 0
		}
	}
    // m2) 2차원 배열 전체를 탐색하며 구름이 있는 지역에서 시작하여 없는 동안 반복함
	for(int i = 0; i < n; i++){ 
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0){ // 만약에 구름이 있으면
				int cnt = 1;
				while(a[i][j + 1] == -1){ // 오른쪽으로 한칸 이동한 곳이 구름이 없는 지역이면
					a[i][j + 1] = cnt++; // 후위증가 => a에 증가하기 전 cnt가 할당되고, cnt가 증가한다 ()
					j++;
				} 
			}
		} 
	} 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << a[i][j] << " ";
		cout << "\n";
	} 
	return 0;
}