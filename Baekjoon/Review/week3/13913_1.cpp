// prev[next] = here 이용 !
#include <bits/stdc++.h>
using namespace std;
#define prev aaa
const int MAX = 200000;
int n, k, here, ret;
int visited[MAX + 4], prev[MAX + 4];
int main(){
    cin >> n >> k;
    queue<int> q;
    vector<int> v;
    visited[n] = 1;
    q.push(n);

    while(!q.empty()){
        here = q.front();
        q.pop();
        if(here == k){ // 이 코드가 들어가야 k까지 도착하는 경로를 추적할 수 있음!
            ret = visited[k];
            break;
        }
        for(int next : {here+1, here-1, here*2}){
            if(next < 0 || next > MAX || visited[next]) continue; // 이전에 방문했던 정점은 방문하지 않음
            prev[next] = here;
            visited[next] = visited[here] + 1;
            q.push(next);
        }
    }
    for(int i = k; i != n; i = prev[i]){
        v.push_back(i);
    }
    v.push_back(n);
    cout << ret - 1 << "\n";
    reverse(v.begin(), v.end());
    for(int i : v) cout << i << " ";
    return 0;
}