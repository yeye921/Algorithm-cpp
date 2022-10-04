// 2차원 벡터 초기화하는 방법
#include <iostream>
#include <vector>
#define M 3
#define N 4
using namespace std;
int main(){
    // vector 요소를 채울 기본 값 설정
    int default_val = 1;

    vector<vector<int>> v; // 기본 2차원 벡터

    // 1. 한번에 초기화
    vector<vector<int>> matrix(M, vector<int>(N, default_val)); // 차이: 두번째 파라미터 값

    // 2. 위의 초기화 과정을 둘로 나눌 수 있음
    vector<int> v(N, default_val);     // N: 벡터 크기, default_val: 초기화할 값
    vector<vector<int>> matrix(M, v);  // M: 2차원 벡터 크기(=행개수), v: 벡터 matrix를 채울 벡터들
}