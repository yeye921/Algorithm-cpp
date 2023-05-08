// 최빈수를 출력하는 프로그램 (중요: 최빈수가 여러개면 가장 큰 점수 출력!)
// 점수가 41이면 scores[41] = cnt+1 이런식으로 저장하고 배열의 가장 큰 값 찾는 식으로 품

// 최대값이 여러개인지 어떻게 확인하지? => 배열 탐색하면서 최대값과 같은게 몇개인지 확인
#include <iostream>
using namespace std;
int T, test_case, n, num;
int scores[1004];
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin >> n; // 테스트케이스 번호 입력받음
        int ret = 0;
        memset(scores, 0, sizeof(scores));
        for(int i = 0; i < 1000; i++){
            cin >> num;
            scores[num] += 1;
        }

        int mx = *max_element(scores, scores + 1004);

        // 최대값이 여러개면 가장 큰 수를 출력해야함 => 아래와 같이 구현하면 해결됨!
        // 어차피 최대값이 여러개면 인덱스가 가장 큰 것이 가장 큰 수이기 때문에 인덱스 끝부터 탐색하면 됨
        // 최대값이 하나여도 동일함
        // 점수는 0부터 100이므로 인덱스는 다음과 같이 설정하면 됨
        for(int i = 100; i >= 0; i--){
            if(scores[i] == mx){
                ret = i;
                break;
            }
        }
        else cout << "#" << n << " " << ret << "\n";
    }
}