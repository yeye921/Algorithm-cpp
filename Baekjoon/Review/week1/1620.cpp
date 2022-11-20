#include <bits/stdc++.h>
using namespace std;
int n, m;
string poket[100001];
string problem;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){ // 1번부터 시작
        cin >> poket[i];
    }

    for(int i = 0; i < m; i++){ // 문제가 들어옴
        cin >> problem;

        if(atoi(problem.c_str()) == 0){ // 이름이 들어오면
            cout << find(poket, poket + 100001, problem) - poket << "\n"; // 여기서 시간복잡도 초과 (n^2)
        } else { // 번호가 들어오면
            cout << poket[atoi(problem.c_str())] << "\n";
        }
    }
}