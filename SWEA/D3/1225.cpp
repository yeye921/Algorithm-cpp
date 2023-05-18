// 다음 주어진 조건에 따라 n개의 수를 처리하면 8자리의 암호를 생성할 수 있다.
// 배열을 돌면서 앞뒤로 삭제하고 삽입하는 연산이 많음 => deque 자료구조가 더 효율적일듯!
// Queue 에서는 원소를 접근하기 위해서 front를 통해 하나씩 가져왔다면, Deque는 iterator와 index 접근이 모두 가능하다!
#include <iostream>
#include <deque>
using namespace std;
int T;
int main(){
    while(cin >> T){
        deque<int> dq;
        for(int i = 0; i < 8; i++){
            int data;
            cin >> data;
            dq.push_back(data);
        }
        while(1){ // 사이클
            bool flag = 1;
            for(int i = 0; i < 5; i++){ // i번째 있는 걸 꺼내야함
                int num = dq.front();
                num -= (i + 1); // 1) i+1만큼 감소
                if(num <= 0){  // 0이하가 되면 종료
                    num = 0;
                    flag = 0;
                }
                dq.pop_front();
                dq.push_back(num); // 2) 뒤로 이동시킴
                if(!flag) break;
            }
            if(!flag) break;
        }
        cout << "#" << T << " ";
        for(int i = 0; i < 8; i++){
            cout << dq[i] << " ";
        }
        cout << "\n";
    }
}