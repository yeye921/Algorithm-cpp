#include <bits/stdc++.h>
using namespace std;
const int max_n = 1501;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int visited_swan[max_n][max_n], visited[max_n][max_n], R, C, day, swanY, swanX;
char _map[max_n][max_n];
bool isSwanMeet;
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;
string s;
void Qclear(queue<pair<int, int>> &q){
    queue<pair<int, int>> empty;
    swap(q, empty);
}
void water_melting(){
    while(waterQ.size()){
        tie(y, x) = waterQ.front();
        waterQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) continue;
            if(_map[ny][nx] == 'X'){
                visited[ny][nx] = 1;
                water_tempQ.push({ny, nx});
                _map[ny][nx] = '.';
            }
        }
    }
}
bool move_swan(){
    while(swanQ.size()){
        tie(y, x) = swanQ.front();
        swanQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
            visited_swan[ny][nx] = 1;
            if(_map[ny][nx] == '.') swanQ.push({ny, nx});
            else if(_map[ny][nx] == 'X') swan_tempQ.push({ny, nx}); // 그 다음턴에 탐색할 것들
            else if(_map[ny][nx] == 'L') return true;
        }
    }
    return false;
}
int main(){
    cin >> r >> c;
    for(int i = 0; i < R; i++){
        cin >> s;
        for(int j = 0; j < c; j++){
            _map[i][j] = s[j];
            if(_map[i][j] == 'L'){swanY = i, swanX = j;}
            if(_map[i][j] == '.' || _map[i][j] == 'L')visited[i][j] = 1, waterQ.push({i, j});
        }
    }
    // 백조 이동하기위한 초기처리
    swanQ.push({swanY, swanX});
    visited_swan[swanY][swanX] = 1;

    while(true){
        if(move_swan()) break;
        water_melting();
        waterQ = water_tempQ;
        swanQ = swan_tempQ;
        
        // tempQ 초기화
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }
    cout << day << "\n";
    return 0;
}