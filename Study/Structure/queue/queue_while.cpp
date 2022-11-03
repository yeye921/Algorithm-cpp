// 보통 queue는 size()와 함께 쓰임
// pop을 하면 size가 작아지고 그러다 0이되면 false가 되면서 while문이 종료가 되어 루프를 빠져나오는 로직
#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    for(int i = 1; i <= 10; i++) q.push(i); // q = {1,2,3,..., 10}
    while(q.size()){
        cout << q.front() << " ";
        q.pop();
    }
}