// 내 풀이 (완전탐색 & 백트래킹 이용)
// 중복된 숫자를 visited로 처리하는 방법 => 이 문제에서는 이렇게 해도 되지만 백준12851같은 문제는 누적해서 더해줘야함
#include <bits/stdc++.h>
using namespace std;
int n;
int mn = 1000000; // 최솟값은 항상 최댓값부터 갱신!
int visited[1000004];
void dfs(int x, int dep){ // dep: 연산을 사용하는 횟수
    // 기저사례
    if(x == 1) {
        mn = min(mn, dep);
        return;
    }
    // 백트래킹 (연산의 횟수가 최솟값 초과, 이미 방문한 경우)
    if(dep > mn || visited[x]) return;

    // 완전탐색
    if(x % 3 == 0) dfs(x/3, dep+1);
    if(x % 2 == 0) dfs(x/2, dep+1);
    dfs(x-1, dep+1);

}
int main(){
    cin >> n;
    dfs(n, 0);
    cout << mn << "\n";
}