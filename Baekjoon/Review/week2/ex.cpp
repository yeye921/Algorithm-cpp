#include <bits/stdc++.h>
using namespace std;
const int v = 10;
bool a[v][v], visited[v];
void go(int from){
    visited[from] = 1; // 방문 처리
    for(int i = 0; i < v; i++){ // 해당 정점과 연결된 정점들 탐색함
        if(visited[i]) continue; // 이미 방문한 정점일 경우, 건너뜀
        if(a[from][i]){
            go(i); // 해당 정점과 연결된 정점 중 방문 안한 정점을 방문함 !!
        }
    }

    return;
}
int main(){
    a[1][2] = 1, a[1][3] = 1, a[3][4] = 1;
    a[2][1] = 1, a[3][1] = 1, a[4][3] = 1;

    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(a[i][j] && visited[i] == 0){ // 간선이 존재하고, 방문 안한 정점일 경우
                go(i);  // 방문!
            }
        }
    }

}