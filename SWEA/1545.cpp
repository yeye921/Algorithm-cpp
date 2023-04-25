// 주어진 숫자부터 0까지 순서대로 찍기
// m1) for문 이용
// m2) while문 이용
#include <iostream>
using namespace std;
int n;
int main(){
    cin >> n;
    for(int i = n; i >= 0; i--){
        cout << i << " ";
    }
}

// m2)
// cin >> n;
// cout << n << " ";
// while(n--){
//     cout << n << " ";
// }