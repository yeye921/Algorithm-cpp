// 10개의 수를 입력 받아, 최대 수와 최소 수를 제외한 나머지의 평균값을 출력하는 문제
// : 최대, 최소값을 구한 뒤 빼주고 평균 계산하기 (수의 개수는 10개로 고정됨)

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
        double ret = 0;
        // 최대값은 최소값부터, 최소값은 최대값부터
        int mx = 0;
        int mn = 10000;
        for(int i = 0; i < 10; i++){
            cin >> n;
            ret += n;
            if(n > mx) mx = n;
            if(n < mn) mn = n;
        }
        ret -= mx + mn;
        ret /= 8;
        cout << "#" << test_case << " " << round(ret) << "\n";
    }
}