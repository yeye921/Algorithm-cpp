// 문제에서 "가장 빠른 시간"이라고 나옴 => BFS(가중치가 같은 그래프 내 최단거리) 문제임 !
// 원래 BFS에서는 한 정점에서 4방향을 탐색함 => 여기서는 {x-1, x+1, 2*x}가 가능

// 구하는 것이 칸의 소모횟수가 아니라 시간이면 ret에서 1을 빼줘야 한다
// 사실 경우의 수는 더하기이다 ! (상의:3개, 하의:3개 => 경우의 수: 3+3=6개)

// +) 엣지 케이스 만드는 법 (꿀팁)
// 항상 문제에서 주어진 테스트케이스외의 경우의 수를 생각해봐야함
// (문제 예시 = n과 m이 다른 경우)이면 => n과 m이 같은 경우에 대한 케이스를 생각해봐야함
// 문제에서 주어진 최소/최대 부분을 생각해야함 (최소/최대부분에 해당하는 테스트 케이스 만들어서 돌려보기!)
// 제출횟수가 상관 없으면 제출하고 테스트케이스를 생각해도 됨
// 제출횟수가 상관 있으면 테스트케이스를 면밀히 따져보고 제출해야함

// 배워야 할 점
// cnt배열로 해당 거리가 나오는 방법 카운트 한 것 !
// 이미 방문했으나 최단거리인 경우에 대한 처리 !

// 내 풀이: BFS를 진행하다가 m과 같아지면 종료.
// 큰돌 풀이: max(10만)까지 전부 BFS 돌리고 visited[k]를 출력하는 것!
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000; 
int visited[MAX+4];
long long cnt[MAX+4]; // 해당거리가 나오는 "방법의 수"를 세는 배열
int main() {
    int n, m;
    cin >> n >> m;
    if(n == m){ // 반례: n과 m이 같을 경우 (이거 처리 안하면 틀림)
        puts("0"); puts("1");
        return 0; 
    } 
    visited[n] = 1;
    cnt[n] = 1; // 초기값을 1로 설정
    queue<int> q;
    q.push(n);
    while (!q.empty()) { // BFS로 가장 빠른 시간 구하기
        int now = q.front();
        cout << now << " " << cnt[now] << "\n";
        q.pop();
        for (int next : {now-1, now+1, now*2}) { // 3가지 방향 탐색
            if (0 <= next && next <= MAX) { // 문제에서 주어진 범위 체크 (중요)
                if (!visited[next]) { // 방문하지 않았다면
                    q.push(next); 
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now]; // !! 경우의 수는 이런식으로 더하기만 하면 됨
                } else if (visited[next] == visited[now] + 1) { // 중요!! 이미 방문했으나 최단 거리인 경우(=최단거리인 또 다른 방법이 있으면 +1)
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout << visited[m] - 1 << '\n'; // !! 초기 정점을 방문처리 하기 위해 1부터 시작했음으로 마지막에 1을 빼줘야함
    cout << cnt[m] << '\n';
    return 0;
}