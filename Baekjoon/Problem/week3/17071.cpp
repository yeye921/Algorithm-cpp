// 문제에서 필요한 핵심로직 두가지 (이 2가지만 구현하면 OK !)
// 1. 수빈이와 동생이 같이 이동하면서 만나는 경우의 수를 체크하는 로직
// 2. 수빈이는 +1,-1로 이동가능하기때문에 동생이 3초에 도착한 지점을 수빈이가 1초에 미리 도착했다면 방문가능하다 ! 
// (단, 제한사항 존재 > 홀,짝을 맞춰줘야 함) ex. 수빈:5초, 동생:7초, 9초 모두 가능, 수빈이가 6초면 안됨
// 즉, 홀짝을 맞춰주고 그 지점에 수빈이가 동생보다 먼저 도착했다면 가능하다

// 보통 상태값이 2개면 2차원 배열을 만들지만 (ex. int a[y][x]) 공간복잡도를 고려해야함
#include <bits/stdc++.h>
using namespace std;
const int max_n = 500000; 
// 50만 * 50만으로 2차원 배열 만들어서 수빈이, 동생위치를 각 인덱스에 저장해도 되지만 공간복잡도를 생각해서 홀/짝으로 하는 방법 생각해낸것 ! 
// 수빈이는 홀짝만 체크하면 되니까 첫번째에 넣고 동생은 위치를 알아야하니까 두번째에 저장
// visited 배열: 수빈이가 홀/짝턴에 해당위치를 방문했는지를 체크하는 용도
int visited[2][max_n + 4]; // 첫번째인자: 해당 턴이 홀/짝인지 나타냄, 두번째인자: 동생의 위치 
int a, b, ok, turn = 1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    if(a == b){cout << 0 << "\n"; return 0;}
    queue<int> q;
    visited[0][a] = 1; // 수빈이가 방문을 시작
    q.push(a);
    while(q.size()){
        b += turn; // 동생의 이동거리 증가
        if(b > max_n)break;  // 50만 넘으면 종료
        if(visited[turn % 2][b]) { // 1. 수빈이가 동생의 위치에 이미 방문을 했고 홀/짝이 맞는다면 (turn은 홀짝을 반복하면서 증가함)
            ok = true;
            break;
        }
        int qSize = q.size();
        // 플루드필 알고리즘 (단계별로 색깔을 칠하는 알고리즘)
        // 지금 우리가 하고 싶은 것은 BFS에 같은 레벨에 있는 것들을 묶어서 진행하고 싶음 > 이럴때 큐 사이즈 사용함 !
        // 즉, 큐 사이즈를 이용하면 턴을 분리할 수 있다 !
        for(int i = 0; i < qSize; i++){
            int x = q.front(); q.pop();
			for(int nx : {x + 1, x - 1, x * 2}){
                if(nx < 0 || nx > max_n || visited[turn % 2][nx]) continue;
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1; // 턴을 증가시킴..?
                if(nx == b){ // 2. 수빈이와 동생의 위치가 동일하면 (함께가면서 체크)
                    ok = 1; break;
                }
                q.push(nx); 
			} 
			if(ok)break;
        }
        if(ok)break;
        turn++;
    }
    if(ok) cout << turn << "\n"; // ok: 수빈이와 동생이 만났는지 체크하는 변수
    else cout << -1 << "\n";
    return 0;
}
