// 큰돌 풀이를 내가 이해하기 쉽게 조금 수정한 코드 !

// bfs로 풀어야 탐색하다가 k만나면 다같이 종료됨 !
// 이전 문제와 유사: 가장 빠른 시간만 찾기 => BFS 이용

// 방법이 몇개인지 구하는 법: cnt를 배열로 저장하는 것! (index: 최단거리값, cnt[idx]: 방법의 개수)
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n, k;
int visited[MAX + 4]; // 최단거리 배열 !
int cnt[MAX + 4];
int ret = 987654321;
void bfs(int n){
    queue<int> q;
    visited[n] = 1;
    q.push(n);
    while(q.size()){
        int now = q.front();
        // cout << now << " : " << visited[now] << " : " << cnt[now] << "\n";
        q.pop();

        for(int next : {now - 1, now + 1, now * 2}){
            if(next < 0 || next > MAX) continue;  // 항상 하기전에 범위 체크해야 함 (결과가 10만이넘어가면 체크할 필요없음)
            if(!visited[next]){
                visited[next] = visited[now] + 1;
                q.push(next);
                cnt[next]++;
            } else if(visited[next] == visited[now] + 1){
                cnt[next]++;
                q.push(next);
            } // +) 이미 방문했는데 최단거리가 아닌 경우면 건너뜀
        }
    }
}
int main(){
    cin >> n >> k;
    if(n == k){
        cout << "0\n";
        cout << "1\n";
        return 0;
    }
    bfs(n);
    cout << visited[k] - 1 << "\n";
    cout << cnt[k] << "\n";
    return 0;
}
// 반례: (0 3 => 3 2), (7 0 => 7 1), (4 9 => 2 1), (4 12 => 3), (4 5 => 1 1)