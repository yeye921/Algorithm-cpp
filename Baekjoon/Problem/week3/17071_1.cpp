// 수빈이가 동생을 찾는 가장 빠른 시간을 출력
// 수빈이가 동생을 찾을 수 없거나, 찾는 위치가 500000을 넘는 경우에는 -1을 출력

// 동생 위치(정수), 수빈이의 위치에 대한 범위 처리

// 백트래킹이나 케이스에 대한 고려가 필요한 문제
// n > k 경우 => 여기가 문제! > 줄이는 과정만 필요 -1만 진행 
// n = k 경우 => o
// n < k 경우 => 문제 없음

// 테스트 케이스가 너무 친절한 문제... 그거 아니였음 이미 틀렸음 ㅠ

// 방문처리를 할건지 안할건지 => 왠지 하면 안될 것 같음
#include <bits/stdc++.h>
using namespace std;
const int MAX = 500000;
int n, k, cnt;
int visited[MAX + 4];
int sister[MAX + 4];
int main(){
    bool flag = 0;
    queue<int> q;
    cin >> n >> k;
    
    visited[n] = 1;
    q.push(n);
    int term = 0;
    while(q.size()){
        flag = 0; // 이동이 불가능한 경우에 대한 처리
        int now = q.front();
        q.pop();

        if(!sister[visited[now]]){ // 동생(k)의 이동 처리 (인덱스(=현재최단시간) <-> k값 매핑)
            sister[visited[now]] = k + term;
            k = sister[visited[now]];
            term++;
            cnt++;
            if(k > 500000){ // 동생의 위치가 50만이 넘으면 -1 출력
                cout << -1 << "\n";
                break;
            } 
        }
        // cout << now << " " << k << "\n";
        cout << now << " " << visited[now] << "\n";
        if(now == k){ // 수빈이가 동생을 찾으면 출력 후 종료
            cout << visited[now] - 1 << "\n";
            return 0;
        }
        for(int next : {now-1, now+1, now*2}){ 
            if(next < 0 || next > MAX || (next != k + term && visited[next])) continue; // next == k인 경우면 큐에 집어 넣어야함 !
            visited[next] = visited[now] + 1;
            q.push(next);
            flag = 1;
        }
    }
    // 이동이 불가능하면(즉, 큐가 다 비었는데 n과 k가 다를 경우)
    if(flag == 0){
        cout << -1 << "\n";
    } 
    return 0;
}