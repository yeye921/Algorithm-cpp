// 규칙1: 처음과 끝은 항상 1
// 규칙2: 나머지 숫자는 그 전 단계의 숫자들을 2개씩 더해가며 구한다
#include <iostream>
#include <vector>
using namespace std;
int T, test_case;
int n;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        vector<int> v[13];
        cin >> n;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i) v[i].push_back(1); // 규칙1
                else {
                    v[i].push_back(v[i-1][j-1] + v[i-1][j]); // 규칙2
                }
            }
        }
        cout << "#" << test_case << "\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }
}