#include <bits/stdc++.h>
using namespace std;
vector<int> v[10]; // 벡터를 10개 가짐. 
vector<int> v(n, 0); // 벡터 크기 n, 0으로 채움

// vector로 2차원 배열 매트릭스 만들기
vector<vector<int>> checked;
vector<vector<int>> v(n + 1, vector<int>(n + 1, 0)); // 두번째 인자는 각 벡터를 채울 값
int main(){
    fill(v.begin(), v.end(), 0);
    memset(check, 0, sizeof(check));
}