// 최종 성적이 주어질 때, 성적이 좋지 못한 7명의 학생의 성적을 오름차순으로 출력
// 우선순위 큐는 알아서 내림차순 정렬됨
// 점수가 0.001 단위이다 > 실수형 타입 사용
#include <bits/stdc++.h>
using namespace std;
int n;
double temp;
priority_queue<double> pq;
vector<double> v; // 7명 성적을 담을 배열
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(pq.size() == 7){
            pq.push(temp); // 새로운 성적을 추가
            pq.pop(); // 가장 높은 성적을 큐에서 제거 > 결국 pq에는 하위 7명의 성적만 남게 됨
        } else pq.push(temp);
    }

    while(pq.size()){ // 오름차순 출력을 위한 작업
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(), v.end());
    for(double i : v) printf("%.3lf\n", i); // 소수점 3자리까지 출력.
    return 0;
}