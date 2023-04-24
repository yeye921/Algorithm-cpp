// 1부터 주어진 값까지의 합을 구하는 프로그램
// m1) 등차수열의 합 공식 이용
// m2) 반복문 이용해서 하나씩 더하기 
#include <iostream>
using namespace std;
int n, ret;
int main(){
    cin >> n;
    ret = (n * (n + 1)) / 2;
    cout << ret << "\n";
}