// -10만 ~ 10만까지의 숫자가 일렬로 써있을 때, 사람들은 10만이 쓰인 위치에서 최대한 0에 가까운 위치로 던지려고 함
// 가장 0에 가깝게 떨어진 돌의 위치와 그 위치에 던진 사람 수를 출력하는 문제
#include <iostream>
using namespace std;
int T, test_case;
int n, dist;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        int cnt = 0;
        int near = 100001; // 최소값을 여기서 초기화해야함! (테스트케이스 문제이므로)
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> dist;
            if(abs(dist) < near){
                near = abs(dist);
                cnt = 1; // cnt 초기화
            } else if(abs(dist) == near) cnt++;
        }
        cout << "#" << test_case << " " << near << " " << cnt << "\n";
    }
}