// 조합을 구현하는 방법: 1.재귀함수 2. n중 for문
// 순열을 구현하는 방법: 1. next_permutation 이용, 2. 재귀함수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
void printV(vector<int> &v){
    for(int i: v) cout << i << " ";
    cout << "\n";
}
void makePermutation(int n, int r, int depth){
    if(r == depth){
        printV(v);
        return;
    }
    for(int i = depth; i < n; i++){
        swap(v[i], v[depth]);
        makePermutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
    return;
}
int main(){
    for(int i = 1; i < 4; i++) v.push_back(i);

    // 순열1) next_permutation 이용
    // do {
    //     for(int i : v) cout << i << " ";
    //     cout << "\n";
    // } while(next_permutation(v.begin(), v.end()));

    // 순열2) 재귀함수 이용
    makePermutation(3, 3, 0);
    return 0;
}