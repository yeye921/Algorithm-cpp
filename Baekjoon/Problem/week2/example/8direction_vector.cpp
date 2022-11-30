 // 8가지 방향 탐색 예제
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main(){
    int y = 0, x = 0;
    for(int i = 0; i < 8; i++){ // 8가지 방향탐색
        int ny = y + dy[i];
        int nx = x + dx[i];
        cout << ny << " : " << nx << "\n";
    }
    return 0;
}