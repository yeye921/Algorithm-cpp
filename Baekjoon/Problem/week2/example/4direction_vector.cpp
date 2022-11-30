// 4가지 방향 벡터 탐색 예제
// {0, 0}좌표에서 dy, dx를 만들어 4방향을 탐색하며 좌표를 출력해라
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int main(){
    int y = 0, x = 0;
    for(int i = 0; i < 4; i++){ // 4방향 탐색
        int ny = y + dy[i];
        int nx = x + dx[i];
        cout << ny << " : " << nx << "\n";
    }
    return 0;
}