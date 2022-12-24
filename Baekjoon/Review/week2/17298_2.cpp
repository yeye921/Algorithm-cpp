// 스택을 이용한 짝짓기 문제 ! => 이걸 빨리 파악하는게 중요
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000004], ret[1000004];
stack<int> stk;
int main(){
    memset(ret, -1, sizeof(ret)); // -1로 초기화 (중요!!)
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];

        while(stk.size() && a[stk.top()] < a[i]){
            ret[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(int i = 0; i < n; i++){
        cout << ret[i] << " ";
    }
    cout << "\n";
    return 0;
}