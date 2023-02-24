// 이 풀이가 도저히 이해가 안가거나 생각해내지 못할 것 같으면 그냥 알아만 두기 !!

// 큰돌 풀이 (비트마스킹을 이용한 풀이)
// 어떠한 x를 받았을 때, 얘를 이진수로 나타내고 1의 개수를 출력하는 문제 > 교안 125p에 나와있음
// 23을 이진수로 나타내면 10111 > 따라서 총 4개(1,2,4,16)로 만들 수 있음 > 답=4

// 이 문제의 포인트: 23을 만들 수 있는 방법 = 16,4,2,1로 쪼개는 것 = 즉, 23을 이진수로 변환하는 것
// 이걸 깨닫는게 핵심 포인트다 ! (근데 쉽지 않음...)
#include <bits/stdc++.h>
using namespace std;
int n, ret = 1; // 마지막이 1로 끝나기 때문에 미리 더해줌
int main(){ 
	cin >> n; 
	while(n != 1){ // n을 이진수로 표현했을 때 1의 개수가 정답이기 때문에 ret++ 해주는 것 
        if(n & 1) ret++; // n & 1는 n % 2 == 1 과 동일한 코드
        n /= 2;
	}
	cout << ret << '\n';

    vector<int> ret;
    int b;
    cin >> n;
    while(n != 1){
        if(n % b == 1) ret.push_back(1);
        else ret.push_back(0);
        n /= 2;
    }
    ret.push_back(1);
    reverse(ret.begin(), ret.end());
    return 0;
}
