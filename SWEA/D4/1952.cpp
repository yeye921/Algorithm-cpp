// 문어박사 풀이
// 가능한 모든 경우를 만들어서 처리하는 완전탐색으로도 풀 수 있다. (최악의 경우 4^12니까 가능)
// 해당 월에서 4가지 이용권을 쓸 경우, 다음 월이 달라질 수 있다 (따라서 기록해야함)

// 가지치기를 해서 좀 더 시간을 줄이는 방법
// 종료조건 추가: if(ans <= sm): return

// 1년동안 각 달의 이용계획을 수립하고, 가장 적은 비용으로 수영장을 이용할 수 있는 방법
// dp로도 풀 수 있는 문제인 것 같음
#include <iostream>
using namespace std;
int T;
int use[14];
int day, mon, mon3, year;
int ans = 3000*12; // 최소값 구하라는 문제는 항상 최대값에서 갱신시키기
void dfs(int month, int sm){ // 완탐 idx와 비용을 인자로 받음
    if(month > 12){ // 재귀함수의 필수조건 (기저사례)
        ans = min(ans, sm); // 최소 비용 갱신
        return;
    }
    // 4가지 경우에 대한 완탐진행
    dfs(month+1, sm + day*use[month]);
    dfs(month+1, sm + mon);
    dfs(month+3, sm + mon3);
    dfs(month+12, sm + year);
}
int main(){
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        fill(use, use + 14, 0);

        cin >> day >> mon >> mon3 >> year; // 이용권 가격 입력받음

        for(int i = 1; i <= 12; i++){ // 12개월 이용계획
            cin >> use[i];
        }

        // 여기서 dfs로 완전탐색 들어가야함
        // 4가지 경우(1일, 1달, 3달, 1년)에 대해 다 돌림 (그림그려보면 쉬움)
        dfs(1, 0); // 첫번째 인자를 month, idx로 생각하면 됨

        cout << "#" << tc << " " << ans << "\n";
    }
}