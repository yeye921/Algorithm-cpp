// 전형적인 완전탐색 문제
// 상당히 쉬운문제지만 시간복잡도가 아리송함 (문제자체는 좋은문제는 아님)
// 시간복잡도는 3^26 > 따라서 이거 너무 오래걸리는데 완전탐색으로 풀어도되나?라고 생각해고 들어가야함 !
// 그래도 이건 완전탐색밖에 풀 방법이 없는데? 하고 풀어야함

// +) 항상 문제를 봤을때 어림잡아 시간복잡도를 계산하고 들어가라 !
// BFS는 너비우선탐색이기때문에 이렇게 DFS처럼 선택해온 경로의 정보를 담기는 힘들다
#include <bits/stdc++.h>
using namespace std;
#define map aaa
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, ret = 1; 
char map[23][23];
bool visited[23][23];
void dfs(int y, int x, vector<char> &v){ // 재귀지만 (이동할 정점없으면) 알아서 종료되므로 기저사례 필요없음
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
        if(find(v.begin(), v.end(), map[ny][nx]) != v.end()) continue; // 현재 알파벳이 이미 벡터에 존재하면 건너뜀
        // 방문처리
        visited[ny][nx] = 1;
        v.push_back(map[ny][nx]);
        
        dfs(ny, nx, v); // dfs 진행
        
        // 원복처리 (=완탐해제)
        visited[ny][nx] = 0;
        v.pop_back();
    }
    ret = max(ret, (int)v.size()); // 가장 최대의 개수가 담김
    // for(char c : v) cout << c << " "; // 디버깅
    // cout << "\n";        
}
int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        string s = "";
        cin >> s;
        for(int j = 0; j < c; j++){
            map[i][j] = s[j];
        }
    }
    vector<char> v; // 알파벳들을 담을 벡터
    // 시작점 처리
    visited[0][0] = 1;
    v.push_back(map[0][0]);
    dfs(0, 0, v);
    cout << ret << "\n";
}