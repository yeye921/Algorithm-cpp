// 10개의 수를 입력 받아, 최대 수와 최소 수를 제외한 나머지의 평균값을 출력하는 문제
// m1) 벡터안에 든 값중 최대, 최소값을 구하는 함수를 통해 구한뒤 총합에서 빼주고 처리함
// m2) 벡터에 값을 다 담고 정렬한 뒤, 맨 앞값과 맨 뒤값을 제외한 합의 평균을 출력

// 평균값을 반올림하기위해 round함수 사용
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int T, test_case;
int n;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        vector<int> v;
        double ret = 0;
        for(int i = 0; i < 10; i++){
            cin >> n;
            ret += n; // 나중에 여기서 최대, 최소값 빼기
            v.push_back(n);
        }
        int mx = *max_element(v.begin(), v.end());
        int mn = *min_element(v.begin(), v.end());
        ret -= mx + mn;
        ret /= (v.size() - 2);
        cout << "#" << test_case << " " << round(ret) << "\n";
    }
}