// 큰돌 풀이

// 문제에 대해 이해안가면 1차원으로 생각하면됨 (0을 만나면 계속탐색, 1을 만나면 멈춰서 cnt셈)
// 그냥 BFS와 달리 1이 레벨의 기준이다 (1이 나오기까지가 한 레벨임)
// => 이걸 구현하는 법: 기존의 BFS +  큐를 2개 사용하는 알고리즘
// ex. # 1 0 1 0 0 * 일 경우 3번만에 만난다

// +) 2차원 좌표를 하나의 int로 표현하는 방법
#include <stdio.h>
#include <iostream>
#include<algorithm>
#include<queue>
using namespace std; 
char a[301][301];
int n, m, x1, y1, x2, y2; 
typedef pair<int, int> pii;
int visited[301][301]; // 문제의 최대범위가 300임
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int ret; 
queue<int> q;
int main(){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    y1--, x1--, y2--, x2--; 
    for(int i = 0; i < n; i++){
        scanf("%s", a[i]); 
    }
    q.push(1000 * y1 + x1); // {y1, x1}을 하나의 숫자로 나타내는 방법 ! (단, 문제최대범위(300)보다 더 큰 값을 곱해줘야함)
    visited[y1][x1] = 1; 
    int cnt = 0;
    // 0을 만나면 계속탐색, 1을 만나면 멈춰서 cnt세는 것을 구현한 코드
    while(a[y2][x2] != '0'){ // 목표지점(초코바 위치)의 값이 0이 되면 종료 ! (종료조건)
        cnt++; // q가 비면 처음부터 다시 시작하면서 cnt++ (레벨링)
        queue<int> temp; // 두번째 큐
        while(q.size()){
            // 큐에 들어있는 하나의 숫자를 아래 연산을 통해 2차원 좌표로 나타낼 수 있다 !
            int y = q.front() / 1000; 
            int x = q.front() % 1000;  
            q.pop();  
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i]; 
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue; 
                cout << ny << " " << nx << "\n";
                visited[ny][nx] = cnt; // 공통으로 방문처리
                if(a[ny][nx] != '0'){ // 만약 좌표의 값이 1, #, *이면
                    a[ny][nx] = '0'; // 0으로 변환
                    temp.push(1000 * ny + nx); // 잠깐 멈췄다가 cnt++(=레벨증가)하고 다음 정점을 다른 큐에 넣음 (temp에는 다음으로  방문할 정점들이 담겨있는 것임)
                }
                else q.push(1000 * ny + nx); // 0이면 레벨을 증가하지 않고 탐색을 계속함 
            } // 큐가 빈다는 뜻은 4방향 탐색한 것들중 0이 없다는 뜻
        }
        q = temp;  // 큐가 비면 temp에 있는 것(값이 1인것)들을 이제 탐색함
        
        // for 디버깅
        cout << cnt << "번째 진행\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    printf("%d\n", visited[y2][x2]); 
}