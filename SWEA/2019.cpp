// 1부터 주어진 횟수까지 2를 곱한 값 구하기
#include <iostream>
#include <cmath>
using namespace std;
int n, ret=1;
int main(){
    cin >> n;
    cout << ret << " ";
    while(n--){
        ret *= 2;
        cout << ret << " ";
    }
    return 0;
}