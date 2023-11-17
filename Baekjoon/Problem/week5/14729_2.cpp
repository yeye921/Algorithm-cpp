#include <bits/stdc++.h>
using namespace std;
int n, cnt; // 8에서 천만까지
vector<double> v; // 7개를 담을 배열
priority_queue<double> grades; // 우선순위 큐는 내림차순으로 자동 정렬됨 (greater쓰면 오름차순)
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        double score;
        cin >> score;
        grades.push(score);
    }

    while(grades.size()){
        if(cnt < 7) {
            printf("%.3f\n", grades.top()); // 소수점 3자리까지 출력하는 코드
            // cout << fixed << setprecision(3) << n << "\n";
            cnt++;
        }
        grades.pop();
    }
    return 0;
}
