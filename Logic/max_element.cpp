// 배열 중 가장 큰 요소 구하는 법 => *max_element(시작주소, 끝+1주소)이용
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a = *max_element(v.begin(), v.end());  // *떼면 배열 중 가장 큰 요소의 위치 반환함
    cout << a << "\n";
    
    return 0;
}