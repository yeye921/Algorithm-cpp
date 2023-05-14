// N명의 사람이 1리터의 쥬스를 나누어 먹으려고 함 
// 모든 사람이 목이 마른 상태이기 때문에 최대한의 쥬스를 마시고자 최선의 전략을 쓴다고 가정
#include <iostream>
using namespace std;
int T;
int n;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin >> n;
        string ret = "1/" + to_string(n);
        cout << "#" << test_case << " ";
        for(int i = 0; i < n; i++){
            cout << ret << " ";
        }
        cout << "\n";
    }
}