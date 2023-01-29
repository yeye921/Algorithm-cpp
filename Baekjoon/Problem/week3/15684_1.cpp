// 가로선은 인접한 두 세로선을 연결해야 한다. 단, 두가로선이 연속하거나 서로 접하면 안된다.
// 또, 가로선은 점선 위에 있어야 한다

// 사다리게임 규칙
// 각각의 세로선마다 게임을 진행함. 세로선의 가장 위에서부터 아래방향으로 내려감. 
// 이때, 가로선을 만나면 가로선을 이용해 옆 세로선으로 이동한 다음, 이동한 세로선에서 아래방향으로 이동해야함

// 목표: i번 세로선의 결과가 i번이 나오게하기 위해 추가해야하는 가로선 개수의 최솟값 (모든 세로선이 결과로 자기 자신이 나와야함)

// 사다리를 어떻게 좌표로 표현할 것인가..
// 완전 탐색 이용

// 한 가로선에서 왔다갔다하면 안됨 ! > 이거 어떻게 처리하지..?
// 사다리 게임 하는걸 구현하는게 의외로 어려움 !
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> added;
int _min = 987654321;
int n, m, h, a, b, cnt;
int _map[33][13], width[33][13]; // 가로선 방문 기록
int game(int idx){ // 각 세로선들이 어디에 도착하는지 이동처리
    // 한 가로선에서 왔다갔다 하지 않도록 중복처리 배열 이용
    int visited[33][13] = {0, };
    int y = 0;
    int x = idx;
    while(y != h){ // y == h가 되면 종료
        // cout << y << " " << x << "\n";
        visited[y][x] = 1; // 방문처리
        if(x == 0){ // 양 끝 세로선이면 하나만 체크
            if(width[y][x] && !visited[y][x + 1]) x += 1;
            else y += 1;
        } 
        else if(x == n - 1){
            if(width[y][x - 1] && !visited[y][x - 1]) x -= 1;
            else y += 1;
        } 
        else {
            if(width[y][x - 1] && !visited[y][x - 1]) x -= 1;
            else if(width[y][x] && !visited[y][x]) x += 1;
            else y += 1;
        }
    }
    // cout << idx << "번 세로선 결과: " << x << "\n";
    return x;
}
bool check(){ // 각 세로선의 결과가 자기자신인지 체크
    bool flag = 1;
    //     for(int i = 0; i < h; i++){ // y
    //     for(int j = 0; j < n - 1; j++){
    //         cout << width[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 0; i < n; i++){
        int dest = game(i);
        if(dest != i){
            flag = 0;
            // break;
        } 
    }
    if(!flag) return false;
    else return true;
}
void go(int cnt, vector<pair<int, int>> &v){
    // 기저사례)
    // 1. 추가한 가로선 개수가 3을 넘으면 종료
    // 2. 각 세로선의 결과가 본인이 나오면 종료
    if(cnt > 3){ 
        // _min = -1; // 이게있으면 이상함
        return;
    }
    // cout << "cnt " << cnt << "\n";
    for(pair<int, int> pi : v){
        width[pi.first][pi.second] = 1;
        // cout << "(" << pi.first << "," << pi.second << ") "<< width[pi.first][pi.second] << "\n";
    }

    if(check()){
        cout << "모두 자기자신 나옴\n";
        _min = min(_min, cnt);
        return;
    }
    // 이거 도저히 안되면 그녕 go의 두번째 인자에 벡터로 담기 (디버깅하기 쉽게)
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n - 1; j++){ // n개의 세로선에서 나올 수 있는 가로선의 수는 n - 1개이다 !
            if(width[i][j]) continue; // 이미 가로선이 존재
            // 만약, 가로선을 추가한다면 연속되는지 좌우로 확인
            if(j >= 1 && width[i][j - 1]) continue; 
            if((j + 1 < n - 1) && width[i][j + 1]) continue;
            // cout << "가로선 추가 " << i << "," << j << "\n";
            width[i][j] = 1; // 방문처리
            v.push_back({i, j});
            go(cnt + 1, v);
            width[i][j] = 0; 
            v.pop_back();
        }
    }
    return;
}
int main(){
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        width[a - 1][b - 1] = 1;
    }
    vector<pair<int, int>> temp;
    go(0, temp);
    // for(int i = 0; i < h; i++){ // y
    //     for(int j = 0; j < n - 1; j++){
    //         cout << width[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << _min << "\n";
    return 0;
}