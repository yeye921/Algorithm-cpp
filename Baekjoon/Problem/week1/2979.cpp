// 이 문제를 봤을 때 counting 배열이 생각나야함 !!
// 문제에 시각이 나오면 (시작한 시간)"이상" (끝난 시간)"미만"으로 잡는게 좋음 !!
// (문제가 잘 안풀릴 때는 입력 부분을 먼저 구현하면 알고리즘이 떠오를 수도 있음)

// 카운팅 배열이 필요한 이유: 어떤 시간에 와있는 트럭의 개수를 세기 위해
#include <bits/stdc++.h>
using namespace std;
int A, B, C, n, m, cnt[100], ret; // cnt: 시간의 범위가 1~100까지로 주어져있음 (전역변수로 선언하면 알아서 초기화 됨)
int main(){
    cin >> A >> B >> C; // 한 대당 금액

    for(int i = 0; i < 3; i++){
        cin >> n >> m;
        // 입력 받고 바로 배열에 값 더해줌
        for(int j = n; j < m; j++) cnt[j]++; // 시작한 시간 "이상" 끝난 시간 "미만"의 예
    }

    for(int i = 1; i < 100; i++){
        if(cnt[i]){
            if(cnt[i] == 1) ret += A;
            else if(cnt[i] == 2) ret += B * 2; // 주차 대수 * 한 대당 금액
            else if(cnt[i] == 3) ret += C * 3;
        }
    }
    cout << ret << "\n";
    return 0;
}