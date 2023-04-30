// 10개의 수를 입력 받아, 최대 수와 최소 수를 제외한 나머지의 평균값을 출력하는 문제
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