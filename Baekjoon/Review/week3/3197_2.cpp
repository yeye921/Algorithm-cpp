#include <bits/stdc++.h>
using namespace std;
const int max_n = 1503;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int r, c, y, x, swanY, swanX, day;
bool isSwanMeet;
char _map[max_n][max_n];
bool visited[max_n][max_n], visited_swan[max_n][max_n];
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;
void clearQ(queue<pair<int, int>> &q){
    queue<pair<int, int>> empty;
    swap(q, empty);
}
void water_melting(){
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
bool move_swan(){
    while(swanQ.size()){
        
    }
    tie(y, x) = swanQ.front();
    swanQ.pop();
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited_swan[ny][nx]) continue;
        visited_swan[ny][nx] = 1;
        if(_map[ny][nx] == '.') swanQ.push({ny, nx});
        else if(_map[ny][nx] == 'X') swan_tempQ.push({ny, nx});
        else if(_map[ny][nx] == 'L') retrun true;
    }

}
int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> _map[i][j];
            if(_map[i][j] == 'L'){swanY = i, swanX = j;}
            if(_map[i][j] == '.' || _map[i][j] == 'L') waterQ.push({i, j});
        }
    }

    // 왜 모든 L들을 swanQ에 안넣는 걸까??
    visited_swan[swanY][swanX] = 1;
    swanQ.push({swanY, swanX});

    while(1){
        if(move_swan()) break;
        water_melting();
        swanQ = swan_tempQ;
        waterQ = water_tempQ;

        clearQ(swan_tempQ);
        clearQ(water_tempQ);
        day++;
    }
    cout << day << "\n";
}