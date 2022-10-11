// 먼저 집어넣은 데이터가 먼저 나오는 자료구조(FIFO, First In First Out)
// 삭제는 맨 앞에서 일어나고 삽입은 맨 뒤에서 일어남
// 삽입, 삭제에 O(1), 탐색에 O(n)이 걸림
// 주로 BFS에 쓰임, 선입선출 구조
#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    q.push(1);
    cout << q.front() << "\n";
    q.pop();
    cout << q.size() << "\n";
    return 0;
}