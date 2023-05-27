// 큐 관련 기본 함수 숙지!
// push_back()은 벡터 관련 함수이다!
// pop(): 큐의 가장 앞에 있는 요소 제거. front(): 가장 앞에 있는 요소를 참조
// 중요) 큐의 가장 뒤에 있는 정수를 출력하는 법
#include <bits/stdc++.h>
using namespace std;
int n;
queue<int> q;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string order;
        cin >> order;
        if(order == "push"){
            int x;
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
            if(q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if(order == "front")
        {
            if(q.size()) cout << q.front() << "\n";
            else cout << "-1\n";
        }
        else if(order == "back")
        {
            queue<int> temp;
            if(q.empty()) cout << "-1\n";
            else {
                int back;
                while(q.size()){
                    back = q.front();
                    temp.push(back);
                    q.pop();
                }
                cout << back << "\n";
                q = temp;
            }
        }
    }
}