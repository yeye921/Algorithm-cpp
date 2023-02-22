// 플루드필 알고리즘
// 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다.

// .:물, X:빙판, L:백조
// 목표: 며칠이 지나야 백조들이 만날 수 있는지 계산

// queue 초기화 하는 법 (빈 큐와 바꿔치기하기)
// queue<pair<int, int>> empty;
// swap(기존 큐, empty);
#include <bits/stdc++.h>
using namespace std;
#define y1 aaa
const int max_n = 1501;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int r, c, y, x, swanY, swanX, day;
int visited_swan[max_n][max_n], visited[max_n][max_n];
bool isSwanMeet;
char _map[max_n][max_n]; // 2000 * 2000 = 4000000 (4백만)
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;
void Qclear(queue<pair<int, int>> &q){
    queue<pair<int, int>> empty;
    swap(q, empty);
}
void water_melting (){
    while(waterQ.size()){ // move_swan과 water_melting 모두 맨 앞에 이게 있어야함 !!
        tie(y, x) = waterQ.front();
        waterQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
            if(_map[ny][nx] == 'X'){
                visited[ny][nx] = 1;
                water_tempQ.push({ny, nx});
                _map[ny][nx] = '.';
            }
        }
    }
}
// 백조 이동 방식도 물이 녹는 방식과 동일함 (.이면 계속이동하다가 X이면 멈춤 > 다음 턴에 X먼저 방문)
// move_swan도 tempQ로 처리해야되는구나 !! (주의)
bool move_swan(){
    while(swanQ.size()){ // 맨 처음에는 하나만 들어있음
        tie(y, x) = swanQ.front(); 
        swanQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited_swan[ny][nx]) continue;
            visited_swan[ny][nx] = 1;
            if(_map[ny][nx] == '.') swanQ.push({ny, nx}); // 물은 건널 수 있음으로 q에 넣음
            else if(_map[ny][nx] == 'X') swan_tempQ.push({ny, nx}); // X는 다음 턴에 방문할 수 있으므로 tempQ에 넣음
            else if(_map[ny][nx] == 'L') return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> _map[i][j];
            if(_map[i][j] == 'L') {swanY = i, swanX = j;}
            if(_map[i][j] == '.' || _map[i][j] == 'L') visited[i][j] = 1, waterQ.push({i, j}); // 백조는 왜 waterQ에 넣어야 됨?
        }
    }
    // 백조 이동하기 위한 초기처리
    swanQ.push({swanY, swanX});
    visited_swan[swanY][swanX] = 1;

    // 로직
    // 1. 백조가 만날 수 있는지 확인
    // 2. 물과 인접한 빙판이 녹는다

    // (이전에 탐색한 것을 패스하고 녹은 것 부터 탐색해야함 !!)
    // .이면 계속 탐색 x를 만나면 tempq에 넣고 탐색 종료
    // 이렇게 하려면 .인 것들을 이미 q에다 넣어놓고 .을 기반으로 탐색해야함
    while(true){ // 이 구조 기억하기
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