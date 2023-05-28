// queue는 앞에서만 끄집어낼 수 있었다면 deque은 앞뒤로 삽입, 삭제, 참조가 가능하다
// 그리고 stack, queue와 달리 요소들을 인덱스 기반으로 접근할 수 있다!
#include <bits/stdc++.h>
using namespace std;
int n, x;
string order;
deque<int> dq;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> order;
        if(order == "push_front"){
            cin >> x;
            dq.push_front(x);
        }
        else if(order == "push_back"){
            cin >> x;
            dq.push_back(x);
        }
        else if(order == "pop_front"){
            if(dq.size()){
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else cout << "-1\n";
        }
        else if(order == "pop_back"){
            if(dq.size()){
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else cout << "-1\n";
        }
        else if(order == "size"){
            cout << dq.size() << "\n";
        }
        else if(order == "empty"){
            cout << dq.empty() << "\n";
        }
        else if(order == "front"){
            if(dq.size()){
                cout << dq.front() << "\n";
            }
            else cout << "-1\n";
        }
        else if(order == "back"){
            if(dq.size()){
                cout << dq.back() << "\n";
            }
            else cout << "-1\n";
        }
    }
}