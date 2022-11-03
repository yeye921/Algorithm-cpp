// 뽑는 갯수(r)이 작을 때 사용하는 방식 (일반적으로 재귀함수 방식 추천)
// 중첩 for문을 이용해 조합을 구현하는 방법 2가지
// 1. i = 0 ~ n, j = i+1 ~ n, k = j+1 ~ n 
// 2. i = 0 ~ n, j = 0 ~ i, k = 0 ~ j
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n = 5;
int k = 3; // 중요: n개를 뽑으면 for문이 n번 중첩된다
int a[5] = {1, 2, 3, 4, 5};
int main(){
    // 1.
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                // cout << i << " " << j << " " << k << "\n";
            }
        }
    }

    // 2.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                cout << i << " " << j << " " << k << "\n";
            }
        }
    }
    return 0;
}