// 벡터를 함수 매개변수로 넘겨서 변화시키고 싶을 때 -> call by reference로 넘겨서 수정하게함
// call by reference: 

// 1) 벡터를 함수 매개변수로 넘길 때
#include <bits/stdc++.h>
using namespace std;
void f(vector<int> &v){
    v[0] = 100; // 벡터 v의 첫번째 원소를 100으로 초기화
}
int main(){
    vector<int> v;
    for(int i = 1; i <= 3; i++) v.push_back(i); // 즉, v = {1, 2, 3}
    f(v);                                       // v = {100, 2, 3}
    for(int i : v) cout << i << " ";
    cout << "\n";
    return 0;
}


// 2) 벡터 배열을 함수 매개변수로 넘길 때

// 3) 2차원 벡터 배열을 함수 매개변수로 넘길 때

