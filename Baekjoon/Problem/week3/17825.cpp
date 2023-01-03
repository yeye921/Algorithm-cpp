// 0 처음에는 시작 칸에 말 4개가 있다
// 1-1 말이 파란칸에서 이동 시작하면 파란색 화살표를 타야함
// 1-2 파란색이 아닌 칸에서 이동을 시작하면 빨간색 화살표를 타야함
// 2 말이 도착 칸으로 이동하면 주사위에 나온 수와 관계 없이 이동을 마친다

// 게임은 10개 턴으로 이뤄짐, 1~5사이의 숫자가 나옴
// 도착 칸에 있지 않은 말을 하나 골라 주사위 수 만큼 이동시킴
// +) 말이 이동을 마치는 칸에 다른 말이 있으면 그 말은 고를 수 없다 (도착 칸 제외)
// 말이 이동을 마칠 때마다 칸에 적혀있는 수가 점수에 추가된다

// 주사위에서 나올 수 10개가 순서대로 주어졌을 때, 얻을 수 있는 점수의 최댓값 출력

// 4개의 말 중 어떤 말을 이동할건지에 대한 경우의 수가 생김
// 이 문제의 시간복잡도는 4^10(약 100만) => 주사위에서 나올 수 10개에 대해 각 4가지 경우가 존재하기 때문 => 이 정도는 완전탐색 가능!
#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, a[10];
const int n = 10;
// 파란색들 저장하는거 만들기..?
int move(int here, int cnt){
    if(here == 100) return 100; // 도착하면 아주 큰 수를 반환
    // 해당 노드에 파란색 화살표가 존재하는 경우 => 빨,파 순서로 큐에 넣음
    if(adj[here].size() >= 2){
        here = adj[here][1];
        cnt--;
    }
    if(cnt){ // 가야될 길이 있다면 => bfs이용해서 쭉쭉가기
        queue<int> q;
        q.push(here);
        int there;
        while(q.size()){
            int x = q.front(); q.pop();
            there = adj[x][0];
            q.push(there);
            if(there == 100) break;
            cnt--;
            if(cnt == 0) break;
        }
        return there;
    }
    else return here;
}
// 도착지점에 말이 있는지 체크
bool isMal(int mal_idx, int idx){
    if(mal_idx == 100) return false;
    for(int i = 0; i < 4; i++){ // 4개의 말 중에서 말의 인덱스가 있는지 파악
        if(i == idx) continue;
        if(mal[i] == mal_idx) return true;
    }
    return false;
}
void add(int here, int there){
    adj[here].push_back(there);
}
// 설명에 나온 그대로 번호를 매기면 안됨 => 중첩된 번호들 존재해서
void setMap(){
    // 이것들은 뭐지..?
    for(int i = 0; i < 19; i++) add(i, i + 1);
    add(5, 21); add(21, 22); add(22, 23); add(23, 24); 
    add(15, 29); add(29, 30); add(30, 31); add(31, 24); 

    add(10, 27); add(27, 28); add(28, 24); add(24, 25); 
    add(25, 26); add(26, 20); add(20, 100);

    // 그림의 바깥쪽 숫자들 > 안쪽 숫자들 순서로 넣음
    // v[i] = j (i: index, j: 원래 문제에 나온 번호)
    v[1] = 2; v[2] = 4; v[3] = 6; v[4] = 8; v[5] = 10; 
    v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20;
    v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30;
    v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40;

    v[21] = 13; v[22] = 16; v[23] = 19; v[24] = 25;
    v[25] = 30; v[26] = 35; v[27] = 22; v[28] = 24;
    v[29] = 28; v[30] = 27; v[31] = 26;
}
int go(int here){
    if(here == n) return 0; // 기저사례
    int ret = 0;
    for(int i = 0; i < 4; i++){ // 4개의 말을 가지고 있음
        int temp_idx = mal[i];
        int mal_idx = move(temp_idx, a[here]); // move함수를 통해 temp_idx를 이동시킴
        if(isMal(mal_idx, i)) continue; // 말이 움직일 수 없는 상태
        // 말이 움직일 수 있는 상태이면
        mal[i] = mal_idx;  // 한번 가보고 (말의 인덱스에 해당하는 정수)
        ret = max(ret, go(here + 1) + v[mal_idx]); // 그 정수들을 더하면서 next 주사위 값으로 go (모든 경우의수 탐색)
        mal[i] = temp_idx; // 초기화, 완전탐색 해제
    }
    return ret;
}
int main(){
    setMap();
    for(int i = 0; i < n; i++) cin >> a[i]; // 주사위 값 입력 받음
    cout << go(0) << "\n";
    return 0;
}