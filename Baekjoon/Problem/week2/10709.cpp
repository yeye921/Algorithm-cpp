// 모든 구름은 1분이 지날 때마다 1킬로미터씩 동쪽으로 이동한다  => x += 1 처리
// 목표: 각 구역에 대해서 지금부터 몇 분뒤 처음으로 하늘에 구름이 오는지 예측 (-1, 0, ?)
// 2차원 배열 초기화 하는 법: fill() 사용, fill은 항상 전체를 초기화해야함 !!
#include <bits/stdc++.h>
using namespace std;
int h, w, cnt, a[104][104];
string s;
char c;
vector<pair<int, int>> v;
int main(){
    fill(&a[0][0], &a[0][0] + 104 * 104, -1);
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> s;
        for(int j = 0; j < w; j++){
            if(s[j] == 'c'){ 
                a[i][j] = 0;  // 구름 시작 좌표 처리
                v.push_back({i, j}); // 구름들 넣기
            }
        }
    }
    // m1) 구름들을 벡터에 넣어놓고 하나씩 이동시키는 방식
    for(auto it : v){
        cnt = 0;
        int y = it.first;
        int x = it.second;
        while(1){ // 바운더리 전까지 구름 이동시키면서 좌표값 변경시키기
            x++;
            cnt++;
            if(y < 0 || x < 0 || y >= h || x >= w || a[y][x] == 0) break; // 다른 구름이 있는 위치 => 종료처리 (방문한 곳 또 방문하면 안되니까)
            else a[y][x] = cnt;
            // cout << "(" << y << "," << x << ")" << cnt << "\n";  // for 디버깅
        }
    }
    // 출력
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}