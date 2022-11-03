// 조합을 중첩 for문으로 구한 예제 2
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n = 5;
int k = 2; // 뽑을 개수 
int a[5] = {1, 2, 3, 4, 5}; // 요 5개 중에 2개 뽑는 경우의 수
int main(){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            // cout << i << " : " << j << "\n"; // 이것들은 인덱스임
            cout << a[i] << " : " << a[j] << "\n";
        }
    }
    return 0;
}
