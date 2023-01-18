#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;
int n, k;
int visited[MAX + 4];
int cnt[MAX + 4]; // 해당 점(인덱스)까지 최단시간으로 올 수 있는 방법의 개수
void bfs(int n){ // dfs와 달리 한번만 호출됨 !
    queue<int> q;
    visited[n] = 1;
    cnt[n] = 1;
    q.push(n);

    while(q.size()){
        int now = q.front();
        q.pop();
        for(int next : {now + 1, now - 1, now * 2}){
            if(next < 0 || next > MAX) continue;
            if(!visited[next]){
                visited[next] = visited[now] + 1;
                q.push(next);
                cnt[next] += cnt[now]; // 이거에 대한 이해가 부족한 것 같음
            }
            else if(visited[next] == visited[now] + 1){ // 최단거리인 경로가 또 존재할 경우
                cout << cnt[next] << " " << cnt[now] << "\n";
                cnt[next] += cnt[now];
                // q.push(next); // 이게 들어가면 틀림 !
            }
        }
    }
}
int main(){
    cin >> n >> k;
    if(n == k){ // n = k에 대한 예외처리
        cout << "0\n";
        cout << "1\n";
        return 0;
    }
    bfs(n);
    cout << visited[k] - 1 << "\n"; // 최단거리 출력
    cout << cnt[k] << "\n";
    return 0;
}