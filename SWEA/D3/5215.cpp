// 민기가 좋아하는 햄버거를 먹으면서도, 정해진 칼로리 이하의 조합 중에서 가장 선호하는 햄버거 조합해주기
// 선호도는 조합된 재료들의 맛에 대한 점수의 합으로 결정됨. 같은 재료를 여러 번 사용할 수 없다

// 목표: 주어진 제한 칼로리 이하의 조합중에서 가장 맛에 대한 점수가 높은 햄버거의 점수를 출력하기
#include <iostream>
#include <vector>
using namespace std;
int T;
int n, l;
int t, k;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){ // vector는 항상 테케문 안에서 선언해야함!
        vector<pair<int, int>> v;
        int ret = 0;
        cin >> n >> l;
        for(int i = 0; i < n; i++){
            cin >> t >> k;
            v.push_back({t, k});
        }
    
        for(int i = 1; i < (1 << n); i++){ // 0~n개를 뽑는 모든 경우의 수
            int calorie = 0;
            int score = 0;
            bool flag = 1;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){  // j: 뽑힌 인덱스
                    score += v[j].first;
                    calorie += v[j].second;
                    if(calorie > l){ // k가 넘어가면 더이상 계산할 필요 없음
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag && calorie <= l){
                ret = max(ret, score); // 점수의 최대값 갱신
            }
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}