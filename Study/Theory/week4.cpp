// 비트 연산자 ~ (one's complement)
// 음수를 표현할 때: (양수의) 비트를 반전한 수 + 1
// ex. 16 = 1000, -16 = 1111,1111,... 10000 (앞에 1로 32bit 꽉 채움)
#include <bits/stdc++.h>
using namespace std;
int main(){
//     int a = 3;
//     cout << (~a) << "\n"; // ~a = - (a + 1)

// // 이 공식 유도 과정
// // -16 = ~16 + 1 (어떤 수를 음수로 표현할 때 사용하는 2의 보수법)
// // -16 - 1 = ~16 > ~16 = -(16 + 1)
// // 즉, ~val = -(val + 1)

// // 비트연산자 활용법 
// // 1) idx번째 비트끄기
// // 이거 다 암기해둬야 함 
//     int S = 18; // 10010
//     int idx  = 1; // 끄고 싶은 비트 인덱스
//     S &= ~(1 << idx);
//     cout << S << "\n";


// // 2) idx번째 비트 XOR(^) 연산 (0은 1로, 1은 0으로 바꾸는 법)
//     int S = 18;
//     int idx = 1;
//     S ^= (1 << idx);
//     cout << S << "\n";


// // 3) 최하위 켜져잇는 비트 찾기 (오른쪽부터 탐색했을때 가장 먼저 1이 나오는 비트)
//     int S = 18;
//     int idx = (S & -S); // -S = ~S + 1
//     cout << idx << "\n";


// // 4) 크기가 n인 집합의 모든 비트를 켜기
//     int n = 4;
//     cout << (1 << n) - 1 << "\n"; // 2^n - 1 = 15


// // 5) idx번째 비트를 켜기
//     int S = 18;
//     int idx = 0;
//     S |= (1 << idx);
//     cout << S << "\n";

// #1 비트마스킹을 이용한 경우의 수
// 모르겠으면 노타빌리티 필기 참고
    const int n = 4;
    string a[n] = {"사과", "딸기", "포도", "배"}; // 각 과일에 대해 2가지 경우 존재 (0:포함x, 1:포함o)
    for(int i = 0; i < (1 << n); i++){
        string ret = "";
        // cout << i << " : ";
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){ // i: boolean배열을 하나로 나타낸 수, j: 처음~끝 비트가 켜져있는지 확인
                // 비트가 하나라도 켜져있으면 if문 통과
                cout << i << " " << j << "\n";
                ret += (a[j] + " ");
            }
        }
        cout << ret << "\n";
    }
    return 0;
}

// #2 비트마스킹을 이용한 매개변수 전달
// 하지만 비트마스킹은 n이 30까지만 가능한 한계가 있다 (그 이상은 시간 초과)
#include <bits/stdc++.h>
using namespace std;
void go(int num){
    string ret = "";
    for(int i = 0; i < 4; i++){
        if(num & (1 << i)) ret += a[i] + " "; // 이전 예제처럼 각 num의 켜진 비트를 찾아서 ret에 저장
    }
    cout << ret << "\n";
    return;
}
int main(){
    const int n = 4;
    string a[4] = {"사과", "딸기", "포도", "배"};

    for(int i = 1; i < n; i++){ // 1은 사과를 의미함
        go(1 || (1 << i)); // visited = 1, go(), visited = 0을 이렇게 비트마스킹을 이용해 한줄로 표현할 수 있다 !!
    }
    return 0;
}