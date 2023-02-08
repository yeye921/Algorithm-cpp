// 내 풀이 > 시간초과나고 답도 이상함
// 이 문제 약간 완전탐색 처럼 가야함 !!!
// 행/열중에 어느걸 먼저 뒤집냐에 따라 최소 개수 달라짐 !!!
// 다시 풀거나 강의 보기 !! (여까지 오는데 1시간 걸림)
#include <bits/stdc++.h>
using namespace std;
char c;
int n;
bool _map[23][23];
void row(int y){ // 해당 행을 뒤집음
    for(int j = 0; j < n; j++){
        if(_map[y][j] == 1) _map[y][j] = 0;
        else _map[y][j] = 1; 
    }
}
void col(int x){
    for(int i = 0; i < n; i++){
        if(_map[i][x] == 1) _map[i][x] = 0;
        else _map[i][x] = 1;
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            if(c == 'T') _map[i][j] = 1;
            else _map[i][j] = 0;
        }
    }
        for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << _map[i][j] << " ";
        }
        cout << "\n";
    }

    // Q. 꼭 이렇게 행/열을 나눠서 탐색해야할까?
    // 1. 행기준 탐색
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(_map[i][j] == 1) cnt++;
        }
        if(cnt > (int)(n / 2)){
            row(i); // 해당 행 뒤집음
        }
    }

    // 2. 열기준 탐색
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(_map[j][i] == 1) cnt++;
        }
        if(cnt > (int)(n / 2)){
            col(i);
        }
    }
    // 1의 개수 세기
    int ret = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(_map[i][j] == 1) ret++;
        }
    }
    cout << ret << "\n";
    return 0;
}