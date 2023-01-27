// 큰돌 풀이: 2차원 좌표(맵)의 모든 정점을 탐색하면서 꽃을 피울 수 있는지 체크 
// 문제 설명
// 자신을 주위로 4방향으로 피는 꽃 구현
// 3개의 꽃 / 이 합이 총 가장 싼 가격
// => 당연히 완전탐색 문제
#include <bits/stdc++.h>
using namespace std;
int n, ret=987654321, v[20][20], p[20][20], dy[4] = { -1,1,0,0 }, dx[4] = {0,0,-1,1};
// v: visited, p: map
int setFlower(int y, int x){ // 꽃을 채움/피움 처리 & 비용 계산
    v[y][x] = 1;
    int s = p[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        v[ny][nx] = 1;
        s += p[ny][nx]; // 화단 가격 계산
    }
    return s; 
}
bool check(int y, int x) { 
    if (v[y][x]) return 0; // 다른 씨앗과 겹침 - 1
    for (int i = 0; i < 4; i++) { // 꽃을 4방향으로 피움
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || v[ny][nx]) { // 다른 꽃과 겹침 - 2
            return 0;
        } 
    } 
    return 1;  
}
void eraseFlower(int y, int x) { // 초기화 (방문처리 지움)
    v[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        v[ny][nx] = 0;
    }
}
void flower(int cnt,int hap) { // 완전탐색. 재귀함수 (여기가 중요!)
    if (cnt == 3) { // 기저사례
        ret = min(ret, hap);
        return;
    }
    for (int i = 0; i < n; i++) { // 맵 전체를 탐색
        for (int j = 0; j < n; j++) { 
            if (check(i, j)) { // 만약에 꽃을 피울 수 있을지 없을지 판단
                cout << i << " " << j << "\n";
                flower(cnt + 1, hap + setFlower(i, j)); // 완탐 진행 (꽃 개수, 비용)
                eraseFlower(i, j); // 완탐 해제

                // 위 두줄 코드는 아래 코드와 같은 의미 (완전탐색 코드)
                // visited = 1;
                // go();
                // visited = 0;
            }
        }
    } 
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    flower(0, 0); 
    cout << ret;
}