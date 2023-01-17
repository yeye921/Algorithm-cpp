// 큰돌 풀이

// 기존 BFS(최단거리 구하기)에 trace(어떤 경로로 왔는지 추적)를 더한 문제
// BFS: 이전 문제처럼 진행
// Trace: prev[next] = here 이런식으로 담으면 됨 (암기!)

// +) 경로를 출력하는 문제는 prev라는 배열을 이용하여 할 수 있다
#include <bits/stdc++.h>
using namespace std;
#define prev aaa
#define next aaaa
// 문제에서 수빈이의 위치(현재점!)이 10만까지로 주어짐 > 이후에는 이 범위를 벗어날 수도 있다 
// 수빈: 6만, 동생: 9만일 때, 수빈이가 12만으로 갔다가 가는게 더 최단거리니까 max값을 이렇게 설정한 것임!
const int max_n = 200004; // 10만 * 2 = 20만
int visited[max_n], prev[max_n], n, k, ret, here, cnt, next;   
vector<int> v; 
queue<int> q;  
int main() { 
    cin >> n >> k; 
    visited[n] = 1; 
    q.push(n);  
    while(q.size()){
        here = q.front();  
        q.pop();
        if(here == k){
            ret = visited[k]; 
            break;
        }
		for(int next : {here + 1, here - 1, here * 2}){
            if(next >= max_n || next < 0 || visited[next]) continue;  
            visited[next] = visited[here] + 1; 
            prev[next] = here; // 처음 수빈이의 위치는 담기지 않음
            q.push(next); 
		} 
    }   
    // for문 이렇게도 쓸 수 있음!
    for(int i = k; i != n; i = prev[i]){ // v에 동생 위치(k)부터 수빈이의 위치(n)까지의 경로가 담김
        v.push_back(i);
    }
    v.push_back(n); // 처음 수빈이의 위치를 담음
    cout << ret - 1<< '\n'; 
    reverse(v.begin(), v.end()); // 배열 순서 뒤집음
	for(int i : v) cout << i << ' '; 
    return 0;
}