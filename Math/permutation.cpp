// 순열: 서로 다른 n개중에 r개를 뽑는 경우의 수 (순서 상관 o) (순서가 정해진 임의의 집합을 다른 순서로 섞는 연산)
// 순열을 코드로 구현하는 첫번째 방법: next_permutation과 prev_permutation을 이용하는 방법
// next_permutation: 오름차순의 배열을 기반으로 순열을 만들 수 있음
// prev_permutation: 내림차순의 배열을 기반으로 순열을 만들 수 있음
// 매개변수로는 순열을 만들 범위를 가리키는 [first, last)를 집어넣음 (순열을 시작할 범위의 첫번째 주소, 포함되지 않는 마지막 주소)
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void printV(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " "; // 벡터요소 이렇게 접근가능
    }
    cout << "\n";
}
int main(){
    int a[3] = {1, 2, 3};
    vector<int> v;
    for(int i = 0; i < 3; i++) v.push_back(a[i]); // v = {1, 2, 3}

    // 1, 2, 3부터 오름차순으로 순열을 뽑는다
    do{
        printV(v); // 출력해줌
    }while(next_permutation(v.begin(), v.end()));

    cout << "--------------" << "\n";
    v.clear();
    for(int i = 2; i >= 0; i--) v.push_back(a[i]); // v = {3, 2, 1}

    // 3, 2, 1부터 내림차순으로 순열을 뽑는다
    do{
        printV(v);
    }while(prev_permutation(v.begin(), v.end()));
    return 0;
}