//  큐에서 원소를 뽑아내는 과정에서 왼쪽으로 한 칸 이동하거나 오른쪽으로 한 칸 이동하는 연산을 사용하여
// 원하는 순서대로 원소를 뽑아내는 과정에서 2번, 3번 연산을 최소로 사용하는 방법을 찾는 문제

/* 
[풀이 방법]
뽑아내려는 수의 위치를 하나씩 확인하면서 다음 과정을 수행함
0. 뽑아내려는 수의 위치를 찾는다
1-1. 왼쪽으로 이동하는 연산의 횟수를 계산한다. 이는 뽑아내려는 수의 인덱스가 현재 큐의 첫번째 원소(인덱스 0)과 얼마나 떨어있는지를 의미함
1-2. 오른쪽으로 이동하는 연산의 횟수를 계산한다. 이는 큐의 크기 n에서 왼쪽으로 이동하는 연산의 횟수를 뺀 값이다
2. 왼쪽으로 이동하는 연산의 횟수와 오른쪽으로 이동하는 연산의 횟수 중 작은 값을 선택하여 더해준다
3. 큐에서 뽑아낸 원소를 제거한다
3. 모든 뽑아내려는 수에 대해 위의 과정을 반복하고, 최종적으로 더한 값을 출력한다 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> positions(M);
    for (int i = 0; i < M; ++i) {
        cin >> positions[i];
    }

    vector<int> queue(N);
    for (int i = 0; i < N; ++i) {
        queue[i] = i + 1;
    }

    int total_count = 0;
    for (int i = 0; i < M; ++i) {
        int left_count = 0;
        int right_count = 0;
        int pos = find(queue.begin(), queue.end(), positions[i]) - queue.begin();

        left_count = pos; // 큐의 앞에서부터의 인덱스
        right_count = queue.size() - pos; // 큐의 뒤에서부터의 인덱스
        
        if(left_count < right_count){
            total_count += left_count;
            while(left_count--){
                // 왼쪽으로 회전
                rotate(queue.begin(), queue.begin() + 1, queue.end());
            }
        } 
        else {
            total_count += right_count;
            while(right_count--){
                // 오른쪽으로 회전
                rotate(queue.begin(), queue.begin() + queue.size() - 1, queue.end());
            }
        }
        queue.erase(queue.begin()); // pop연산은 첫번째 원소에서만 가능하다 
    }
    cout << total_count << "\n";
    return 0;
}
