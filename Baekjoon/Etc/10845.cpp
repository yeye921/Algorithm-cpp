// 큐 관련 기본 함수 숙지!
// push_back()은 벡터 관련 함수이다!
// pop(): 큐의 가장 앞에 있는 요소 제거. front(): 가장 앞에 있는 요소를 참조
// 중요) back(): 큐의 제일 마지막 데이터를 반환하는 함수
// swap(queue1, queue2): 두 큐의 내용을 바꾸는 함수
// empty(): 큐가 비어있으면 1, 아니면 0을 반환하는 함수
#include <bits/stdc++.h>
using namespace std;
int n, x;
queue<int> q;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string order;
        cin >> order;
        if(order == "push"){
            cin >> x;
            q.push(x);
        }
        else if(order == "pop")
        {
            if(q.size()){
                cout << q.front() << "\n";
                q.pop();
            }
            else cout << "-1\n";
        }
        else if(order == "size")
        {
            cout << q.size() << "\n";
        }
        else if(order == "empty")
        {
            cout << q.empty() << "\n";
        }
        else if(order == "front")
        {
            if(q.size()) cout << q.front() << "\n";
            else cout << "-1\n";
        }
        else if(order == "back")
        {
            if(q.size()) cout << q.back() << "\n";
            else cout << "-1\n";
        }
    }
}