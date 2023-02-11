// 큰돌 풀이 (내 풀이보다 800ms 더 빠름)
// 알파벳의 개수가 26개니까 30개이하이므로 비트마스킹으로 풀 수 있는 문제다 ! (포함=1, 포함x=0)

// 비트마스킹을 이용함 (1=A, 2(10)=B, 3(11)=A&B, 4(100)=C, ...) 이런식으로 뽑는 것을 불리언배열이 아닌 하나의 수로 표현함
// ex. ABC를 건너왔으면 1+2+4 = 7로 표현함 
#include <iostream>
#include <algorithm>
using namespace std;
int R, C, ret, ny, nx;
char a[21][21];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = { 0, 1, 0, -1};
void go(int y, int x, int num, int cnt){
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++){
        ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int _next = (1 << (int)(a[ny][nx] - 'A'));
        // num |= _next; // 이런식으로 num에다 직접처리하면 나중에 원복 처리해 줘야 함
        // 아래 코드처럼 매개변수에다가 하면 그렇게 안해도 됨
        // if((num & _next) == 0)으로 if(visited[ny][nx]) continue처리함! 즉, 방문한 곳은 다시 방문하지 않게함
        if((num & _next) == 0) go(ny, nx, num | _next, cnt + 1); // visited = 1, go(), visited = 0 코드 대신에 | 연산자로 대체할 수 있다
    }
    return;
}
int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }
    go(0, 0, 1 << (int)(a[0][0] - 'A'), 1); // a[0][0]을 건넜다는 것을 1 << (int)(a[0][0] - 'A')로 표현함
    cout << ret << '\n';
    return 0;
}
