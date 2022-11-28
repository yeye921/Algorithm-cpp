// 블로그 글 예제 - 인접 행렬
#include <bits/stdc++.h>
using namespace std;
const int v = 10; // 정점 개수
bool a[v][v], visited[v]; // 인접행렬과 방문처리배열 선언
void go(int from){
    visited[from] = 1; // 해당 정점 방문 처리
    cout << from << "\n";
    for(int i = 0; i < v; i++){
        if(visited[i]) continue; // 이미 방문한 정점이면 건너뜀
        if(a[from][i]){ // 해당 정점과 연결된 정점 중 방문 안한 정점을 방문함 !!
            go(i);  
        }
    }   
    return;
}
int main(){
    // 인접행렬 표현
    a[1][2] = 1; a[1][3] = 1; a[3][4] = 1;
    a[2][1] = 1; a[3][1] = 1; a[4][3] = 1;
    // 노드 탐색 -> 이중 for문
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(a[i][j] && visited[i] == 0){ // 정점에 연결된 간선이 존재 & 이전에 방문했던 정점이 아니라면 => 해당 정점 방문
                go(i);
            }
        }
    }
}