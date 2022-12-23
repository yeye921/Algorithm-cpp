// 포인트
// 1. stack에 수열의 인덱스로 담기 => 그래야 ret에 오큰수를 순서대로(인덱스로) 저장가능
// 2. 수열의 원소를 입력받으면서 while로 반복하기 (while의 조건문이 포인트)
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000004], ret[1000004];
stack<int> stk;
int main(){
    fill(&ret[0], &ret[0] + 1000004, -1); // ret을 -1로 초기화 
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];

        while(stk.size() && a[stk.top()] < a[i]){ // while 조건에 이걸 넣는게 포인트!
            ret[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(int i = 0; i < n; i++) cout << ret[i] << " ";
    return 0;
}