// 비트마스킹으로 다시풀기 (430ms)
#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int r, c, ret;
char a[23][23];
void go(int y, int x, int alpha, int cnt){ // cnt로 ret을 업데이트 시켜야 함
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        int next = 1 << (a[ny][nx] - 'A'); // next가 켜져있다는 것을 하나의 숫자로 표현 (비트마스킹)
        if((alpha & next) == 0) go(ny, nx, alpha | next, cnt + 1); // alpha에 다음 알파벳(next)을 포함시킨 것을 넘김
    }
    return;
}
int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }
    go(0, 0, 1 << (a[0][0] - 'A'), 1); // a[0][0]에 적혀있는 알파벳을 포함한다는 의미 !
    cout << ret << "\n";
    return 0;    
}