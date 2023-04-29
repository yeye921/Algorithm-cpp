// n 길이의 숫자열을 오름차순으로 정렬하여 출력하는 문제
// m1) 벡터에 숫자들을 넣고 정렬 함수 이용함
// 주의) 벡터는 memset으로 초기화 못하고 fill로만 할 수 있다!
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T, test_case;
int n, num;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){ // 테스트케이스는 초기화가 중요!
        vector<int> v; // 여기서 선언하는게 중요!!
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        cout << "#" << test_case << " ";
        for(int i : v) cout << i << " ";
        cout << "\n";
    }
}