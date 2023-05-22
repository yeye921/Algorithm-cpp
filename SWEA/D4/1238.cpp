// "가장 나중에 연락을 받게 되는 사람" => 전형적인 BFS 문제
// 가장 마지막에 큐에서 꺼내지고 번호가 가장 큰 사람 구하기

// visited 배열 필요함
// 한 명의 사람이 다수의 사람에게 연락이 가능한 경우 항상 다자 간 통화를 통해 동시에 전달한다
// => 레벨별 탐색이므로 BFS를 사용해야함!

// 한 정점에 연결된 정점이 여러개있으므로 => 연결리스트 사용
// Q. 마지막 레벨인 것을 어떻게 알지..? => 그냥 모든 레벨에서 visited 배열을 이용해 갱신해나감!
// 주의!! BFS에서 visited 배열은 단순 방문처리가 아니라 최단거리 구현을 위해 사용함!!
#include <iostream>
#include <queue>
using namespace std;
int main(){
    for(int tc = 1; tc <= 10; tc++){
        int len;
        int start;
        vector<int> list[104]; // 연략 인원은 최대 100명
        int visited[104] = {0, }; // 방문처리 배열

        cin >> len >> start;
        for(int i = 0; i < len/2; i++){
            int a; int b;
            cin >> a >> b;
            list[a].push_back(b);
        }
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        int ret = start; // 연결된 사람이 나 혼자면 내가 정답이 되니까 그 경우 처리
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // 요 2가지 생각이 이 문제의 key point이다 !!
            if(visited[ret] < visited[node]) ret = node; // 1. 더 늦게 받은 경우에는 늦게 받은 사람으로 갱신
            else if((visited[ret] == visited[node]) && (ret < node)) ret = node; // 2. 동시에 받을 경우에는 번호가 가장 큰 사람으로 갱신함 (주의!!)
            for(int i: list[node]){ // 해당 정점에 연결된 정점들 탐색 (동시에 전달)
                if(!visited[i]){
                    q.push(i);
                    visited[i] = visited[node] + 1; // bfs에서 visited 배열은 최단거리 배열!!
                }
            } 
        }
        cout << "#" << tc << " " << ret << "\n";
    }
}
