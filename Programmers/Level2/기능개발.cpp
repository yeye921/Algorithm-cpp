// 와우 어렵다... (시간 오래 걸림)
// 일단은 벡터의 맨 처음 인자가 100이 되어야됨

// 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.
// 각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.
#include <bits/stdc++.h>
using namespace std;
vector<int> answer;
int visited[104];
int func_num, current_idx;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int len = progresses.size();
    while(current_idx != progresses.size()){ // 다 배포되면 종료됨
        func_num = 0;

        // 맨 첫번째 원소가 100이 넘게 하기
        int dist = 100 - progresses[current_idx];
        int n = dist / speeds[current_idx];
        if(n * speeds[current_idx] != dist) n++;

        for(int i = current_idx; i < len; i++){
            progresses[i] += (speeds[i] * n);
        }

        for(int i = current_idx; i < len; i++){ // 당연히 첫번째 원소는 배포가능함
            if(progresses[i] >= 100 && !visited[i]) { // 100이 넘는 원소를 벡터에서 삭제할 수 없으므로 visited 배열로 배포 여부 체크
                func_num++;
                current_idx++;
                visited[i] = 1;
            } 
            else break; // 배포는 연속적으로 일어나야함
        }
        if(func_num) answer.push_back(func_num); // 배포 개수가 0일 경우에는 넣지 않음
    }
    return answer;
}