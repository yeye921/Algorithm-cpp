// 숫자 범위가 꽤 크기때문에 이렇게 배열 이중 루프로 푸는 방식은 "비효율적"이다. (두번째 방법으로 풀어야 함)
// 최악의 경우: O(n^2). for문을 2번 돈다(1.최대값찾기, 2.금액구하기)

// 풀이 (계속 반복되는 형태)
// 1. start~끝까지 mx_idx 구하기
// 2. for(int i = start, i < mx_idx; i++) ans += (_map[mx_idx] - _map[i])
// 3. s = mx_idx + 1

// 규칙1: 이전날보다 다음날의 숫자가 크면 구입하는 것이 낫다.
// 규칙2: 구입 후, 현재 날이 다음날의 숫자보다 크면 지금 파는 것이 낫다.
// 배열의 가장 큰 수의 위치를 알아야 할듯

// 결론: 배열의 최대값이 존재한다면 그게 나올때까지는 구매하고 해당 인덱스에서 매매함
#include <iostream>
#include <cstring>
using namespace std;
int T, test_case;
int n, num;
int _map[1000004];
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        memset(_map, 0, sizeof(_map));
        cin >> n;
        
        for(int i = 0; i < n; i++){
            cin >> num;
            _map[i] = num;
        }

        // 반복문으로 처리
        // 1. 주어진 배열에서 최대값 구하고 최대값 나오기까지 자르고 매매함
        // 2. 최대값 다음부터 배열 끝까지 또 새로운 최대값 구하고 반복함
    
        int start = 0; // 탐색 인덱스
        int ans = 0;
        while(start < n){
            int mx_idx = start;
            
            // 최대값 인덱스 찾기
            for(int i = start + 1; i < n; i++){
                if(_map[mx_idx] < _map[i]){
                    mx_idx = i;
                }
            }
            for(int i = start; i < mx_idx; i++){
                ans += (_map[mx_idx] - _map[i]);
            }
            start = mx_idx + 1; // 배열의 시작 인덱스를 mx_idx 다음으로 설정해줌
        }
        cout << "#" << test_case << " " << ans << "\n";
    }
}