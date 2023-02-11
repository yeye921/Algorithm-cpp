// 내 풀이 > 처음에 틀림 > 완탐해제하는 코드(v.pop_back())을 빠트림 !!

// dfs로 완전탐색 진행해야 함
// visited로 한번 더 걸러내는거 추가하면 200ms정도 줄일 수 있음
#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int r, c, ret;
char _map[23][23];
void dfs(int y, int x, vector<char> &v){ // visited를 체크할 필요가 없음 (이미 find를 통해서 같은 알파벳이 담겼는지 확인하기 때문에)
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if(find(v.begin(), v.end(), _map[ny][nx]) != v.end()) continue;
        v.push_back(_map[ny][nx]);
        dfs(ny, nx, v);
        v.pop_back();
    }
    ret = max(ret, (int)v.size()); // vector.size()의 반환은 int형이 아님!! 형변환이 필요함
}
int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> _map[i][j]; 
        }
    }
    vector<char> alpha;
    alpha.push_back(_map[0][0]); // 알파벳들을 담을 벡터
    dfs(0, 0, alpha);
    cout << ret << "\n";
    return 0;
}