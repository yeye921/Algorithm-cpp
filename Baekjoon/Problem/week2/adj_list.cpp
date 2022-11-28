// 블로그 글 예제 - 인접 리스트
// 인접리스트: 연결리스트를 여러개 만들어서 그래프를 표현함 (정점마다 연결리스트를 만들고 연결된 정점을 집어넣음)
#include <bits/stdc++.h>
using namespace std;
const int v = 4; // 정점이 4개
vector<int> adj[v];
int main(){
    // 각 정점마다 해당 연결리스트에 연결된 정점들을 집어넣음
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(0);
    adj[2].push_back(1);

    adj[3].push_back(0);

    // 각 정점에 연결된 정점 뽑아내기
    for(int i = 0; i < v; i++){
        cout << i << " :: ";
        for(int there : adj[i]){
            cout << there << " ";
        }
        // for(int j = 0; j < adj[i].size(); j++){
        //     cout << adj[i][j] << " ";
        // }
        cout << "\n";
    }
}