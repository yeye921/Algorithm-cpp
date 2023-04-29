// n 길이의 숫자열을 오름차순으로 정렬하여 출력하는 문제
// m1) 벡터에 숫자들을 넣고 정렬 함수 이용함
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T, test_case;
int n, num;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        vector<int> v;
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