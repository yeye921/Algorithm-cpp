// 상근이가 사과를 모두 담으려고 할 때 바구니의 이동거리의 최솟값을 구해라 => BFS인줄 알았지만 그냥 단순구현 문제

// 이 문제의 핵심인 "이동거리가 최소가 되게 하기위해서는"
// apple이 end보다 클 경우 => end를 apple로 이동시키고
// apple이 start보다 작을 경우 => start를 apple로 이동시킨다
#include <bits/stdc++.h>
using namespace std;
#define end aaa
int n, m, j, start, end, apple, cnt;
int main(){
    cin >> n >> m;
    cin >> j;

    // start는 바구니 시작 위치, end는 바구니 끝 위치
    start = 1;
    end = start + m - 1;

    for(int i = 0; i < j; i++){
        cin >> apple; // 사과 떨어지는 위치

        // 사과가 떨어지는 위치가 바구니 영역(start이상 end이하)에 포함되지 않을 경우를 2가지로 나눔 
        // 둘다 바구니 이동이 필요함 (두가지 경우의 차이에 대해 알아두기)
        if(apple < start){
            int dist = start - apple; // 바구니 이동거리
            // 바구니를 앞으로 이동시키고 이동거리 카운트 해줌
            start -= dist;
            end -= dist;
            cnt += dist;
        }
        if(apple > end){
            int dist = apple - end;
            // 바구니를 뒤로 이동시키고 이동거리 카운트 해줌
            start += dist;
            end += dist;
            cnt += dist;
        }
        cout << start << " " << end << "\n"; 
        // 사과가 바구니 영역 안에 있을 때는 이동시켜줄 필요 없다 => else continue;가 여기에 생략되었음
    }
    cout << cnt << "\n";
    return 0;
}