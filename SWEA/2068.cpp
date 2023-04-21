// 10개의 수 입력 받아 가장 큰 수 구하기
// m1) 배열에 담고 max_element() 이용
// m2) 하나씩 입력받으면서 최대값 갱신해내감
#include <iostream>
#include <algorithm>
int test_case = 0;
int a[13], ret;
int main() {
    cin >> test_case;
    while(test_case--){
        for(int i = 0; i < 10; i++){
            cin >> a[i];
        }
        ret = *max_element(a, a + 10);
        cout << "#" << test_case << " " << ret << "\n";
    }
    return 0;
}