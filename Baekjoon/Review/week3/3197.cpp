#include <bits/stdc++.h>
using namespace std;
const int max_n = 1501;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int r, c, y, x, swanY, swanX, day;
char _map[max_n][max_n];
bool visited[max_n][max_n], visited_swan[max_n][max_n], isSwanMeet;
queue<pair<int, int>> swanQ, swan_tempQ, waterQ, water_tempQ;
void clearQ(queue<pair<int, int>> &q){ // queue 초기화 하는 방법 (큐는 clear함수 없음)
    queue<pair<int, int>> empty; 
    swap(q, empty);
}
// 백조도 .을 만나면 계속 탐색하고 X를 만나면 멈춤 > 다음 턴에 X부터 탐색함
bool move_swan(){
    while(swanQ.size()){
        tie(y, x) = swanQ.front();
        swanQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited_swan[ny][nx]) continue;
            visited_swan[ny][nx] = 1; // 왜 visited 처리를 여기서 해야되지?
            if(_map[ny][nx] == '.') swanQ.push({ny, nx});
            else if(_map[ny][nx] == 'X') swan_tempQ.push({ny, nx});
            else if(_map[ny][nx] == 'L') return true;
        }
    }
    return false;
}
void water_melting(){
    while(waterQ.size()){
        tie(y, x) = waterQ.front();
        waterQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue; 
            // 여기다가는 visited[ny][nx] = 1 안넣음 > 왜? 이미 waterQ에 넣으면서 방문처리 했음
            if(_map[ny][nx] == 'X'){
                visited[ny][nx] = 1;
                water_tempQ.push({ny, nx});
                _map[ny][nx] = '.'; // 다음 턴에 백조가 건너려면 X를 .로 변환 필수 !! (얼음이 물로 녹는다)
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> _map[i][j];
            if(_map[i][j] == 'L'){swanY = i, swanX = j;}
            if(_map[i][j] == '.' || _map[i][j] == 'L'){ // Q. L이어도 이동할 수 있으니까 넣는건가...?
                waterQ.push({i, j});
                visited[i][j] = 1;
            } 
        }
    }
    visited_swan[swanY][swanX] = 1;
    swanQ.push({swanY, swanX});
    
    while(1){
        if(move_swan()) break;
        water_melting();    
        waterQ = water_tempQ;
        swanQ = swan_tempQ;
    
        clearQ(water_tempQ);
        clearQ(swan_tempQ);
        day++;
    }
    cout << day << "\n";
    return 0;
}