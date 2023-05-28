// 중요) 이 문제는 deque 문제이다!
// 타겟의 인덱스를 찾는게 핵심이다 (그걸로 2,3번 중 어떤 연산을 할지 결정함)
// 큐 안의 숫자가 0부터 시작하는지 1부터 시작하는지를 왜 문제에 안써놓지? 예제 보고 유추하라는 건가??
#include <bits/stdc++.h>
using namespace std;
int n, m, x, ans;
vector<int> target; // 뽑아내려고 하는 수의 위치
deque<int> dq;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){ // queue 초기화
        dq.push(i);
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        target.push_back(x);
    }

    // 다들 이런식으로 타겟의 인덱스를 구함 (find 함수도 가능)
    // for(int i = 1; i <= n; i++){

    // }
    for(int i : target){
        if(dq.front() == i){
            dq.pop();
            continue;
        }
        else {
            // 찾는 위치의 현재 위치를 구함 (큐에서 어떻게 구하지?)
            int idx = find(dq.begin(), dq.end(), i);

        }
    }
}