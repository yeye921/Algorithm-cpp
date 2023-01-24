// 대표적으로 두가지의 로직이 필요한 문제
// 1. 백조를 움직이는 것: 하나의 백조를 기반으로 해도 됨
// 2. 물과 인접한 빙하가 물이 되는 것

// 꿀팁) 문제를 단순화할 필요가 있다
// 14497문제와 유사하게 플루드필 알고리즘 이용됨 > 하루 지나면 빙하가 녹고 다음 턴으로 넘어가는 로직

// 플루드필 알고리즘을 구현하는 방법
// 1. Qsize = q.size()로 할당해놓고 하는 방법
// 2. 큐를 2개(tempQ, Q)를 사용하는 방법 (이게 정석!)
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
const int max_n = 1501;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1}; 
int visited_swan[max_n][max_n], visited[max_n][max_n], R, C, day, swanY, swanX, y, x;
char _map[max_n][max_n];
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ; // 큐를 4개 사용
string s;
void Qclear(queue<pair<int, int>> &q){ // tempQ를 초기화시켜주는 함수
   queue<pair<int, int>> empty;
   swap(q,empty); // 빈 큐와 교환
}
// Qclear는 이렇게도 구현가능 (but, 위가 더 빠름)
// while(q.size()){
//     q.pop();
// }
void water_melting(){ // 물과 인접한 빙하를 녹이는 함수
    while(waterQ.size()){
        tie(y, x) = waterQ.front();
        // cout << y << " " << x << "\n";
        waterQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])continue;
            if(_map[ny][nx] == 'X'){ // 물과 인접한 빙하의 경우
                visited[ny][nx] = 1; 
                water_tempQ.push({ny, nx}); // 다음 턴에서는 이 정점들만 탐색하면됨 !
                _map[ny][nx] = '.'; // 빙하를 물로 변환처리 
            } 
        }
    }
}
bool move_swan(){ // 백조 두마리가 만날 수 있는지 백조 이동해서 체크하는 함수 (dfs보단 bfs에 가까움)
    while(swanQ.size()){
        int y = swanQ.front().first;
        int x = swanQ.front().second;  
        cout << y << " " << x << "\n";
        swanQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])continue;
            visited_swan[ny][nx] = 1;
            
            // 아래 3줄이 핵심 ! (여기가 제일 중요)
            if(_map[ny][nx] == '.')swanQ.push({ny, nx}); // 물은 백조 이동가능하므로 현재 큐에 담음
            else if(_map[ny][nx] == 'X') swan_tempQ.push({ny, nx}); // 빙하들을 만나면 tempQ에 담음 (큐사이즈가 증가되지 않으니 시간 지나면 무한루프끝남)
            else if(_map[ny][nx] == 'L') return true; // 백조가 만났으면 true
        }
    }
    return false; // 백조가 안만났으면 false를 반환
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> s;
        for(int j = 0; j < C; j++){
            _map[i][j] = s[j];
            if(_map[i][j] == 'L'){swanY = i; swanX = j;} // 하나의 백조를 기반으로함
            if(_map[i][j] == '.' || _map[i][j] == 'L')visited[i][j] = 1, waterQ.push({i, j}); // 백조가 있는 위치도 물이기때문에 물에다 담음
        }
    }

    swanQ.push({swanY, swanX}); 
    visited_swan[swanY][swanX] = 1; // 백조 이동을 체크할 배열

    while(true){ // move_swan과 isMelting을 반복하며 > move_swan에서 백조를 만나면(1을 반환하면) 종료
        if(move_swan()) break;
        water_melting();

        waterQ = water_tempQ;
        swanQ = swan_tempQ;
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }
    cout << day << "\n";
    return 0;
}