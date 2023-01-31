// DFS & 백트래킹 문제

// 이 문제의 시간복잡도 계산
// 2<=N<=10, 1<=H<=30, 사다리를 최대로 놓을 수 있는 개수 = 3
// 따라서 최대 300 C 3 = 450만이다
// (문제에서 주어지는 조건마다 다르지만 보통 1000만이나 1억이하이면 풀 수 있다)
// 만약 사다리의 개수가 10개까지 가능하면 이 문제는 시간 초과로 인해 완전 탐색으로 풀 수 없다

// +) 백트래킹은 가지치기이다. 방문하지 않아도 될 경우의 수는 생각하지 않는다
// 이 문제는 완탐이 아니라 백트래킹이다 (이유)
// cnt >= 3이되면 종료시켜야하기 때문. 
// cnt를 증가시키면서 go라는 함수를 반복호출할텐데 ret=2로 설정되면 go(?, 3)은 탐색할 필요가 없는 경로이므로 종료시켜야하기 때문.

// 이 문제에 필요한 로직
// 사다리를 놓는 상태를 코드로 구현 > visited[a][b] (a라는 가로선에서 b, b+1사이에 사다리를 놓는 것)

// +) INF: int형이면 1e9(=987654321), long long형이면(=30억이상이면) 1e18
// 이해 안가면 노타빌리티에 구조도 그려놓은거 참고
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321; // INF는 문제의 범위보다 더 큰 값으로 잡음 (여기서는 사다리가 최대 3개니까 그냥 int형으로 잡아줌)
int n, m, h, a, b, ret = INF, visited[34][34];
bool check(){ // i번째 사다리의 결과가 i가 나오는지 확인
    for(int i = 1; i <= n; i++){
        int start = i; // 세로선 i의 사다리타기 x좌표
        for(int j = 1; j <= h; j++){ // y좌표. j가 h가 될 때가지 반복
            if(visited[j][start])start++; // 오른쪽으로 가는 사다리가 있으면 오른쪽으로 이동
            else if(visited[j][start - 1])start--; // 왼쪽으로 가는 사다리가 있으면 왼쪽으로 이동
            // 사다리가 아무것도 없으면 x좌표 이동이 일어나지 않음
        }
        if(start != i) return false; // 시작지점과 도착지점이 다르면
    }
    return true;
}
void go(int here, int cnt){ 
    if(cnt > 3 || cnt >= ret) return; // 백트래킹 !!
    if(check()){ 
        ret = min(ret, cnt); return;
    }
    // 메인로직: 완전탐색 꼴과 똑같음
    // 내 풀이: 2차원 배열 전체를 탐색하면서 가로선을 추가 > 시간초과남 
    // 큰돌 풀이: 내가 이미 지나온 가로선에 대해서는 완전탐색 진행하지 않음 (내가 앞으로 가야할 길에 대해서만 완탐진행) !!! 포인트
    for(int i = here; i <= h; i++){ // 가로선: here부터 h까지 탐색함 (이게 제일 이해 안감) > 같은 가로줄에서 더이상 뽑을 게 없을 때 다음 가로줄(y+1)로 넘어가는 방식임
        for(int j = 1; j < n; j++){ // 세로선
            // 범위를 넘어가는 지는 체크 안함
            if(visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue; // 사다리를 연속해서 놓으면 안됨 (본인, 좌, 우 확인)
            visited[i][j] = 1; // 사다리를 하나 놓음
            cout << here << ": " << i << " " << j << "\n";
            go(i, cnt + 1); // 다음 턴 탐색 진행
            visited[i][j] = 0; // 사다리 원복
        }
    }
    return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        cin >> a >> b; visited[a][b] = 1; // 문제의 예시를 기반으로 visited 정의함
    }
    go(1, 0); // y = 1부터 탐색 시작
    cout << ((ret == INF) ? -1 : ret) << "\n"; // +) 최소값은 항상 최대값부터 시작해서 갱신해나감 !!
	return 0;
}
