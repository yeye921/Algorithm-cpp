// 순열을 코드로 구현하는 두번째 방법: 재귀를 이용한 방법 (전통적)
// 하지만 next_permutation을 이용한 방법이 훨씬 간단함 (추천!)
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int a[3] = {1, 2, 3};
vector<int> v;
void printV(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}
void makePermutation(int n, int r, int depth){
    cout << n << " : " << r << " : " << depth << "\n"; // for debugging
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
    for(int i = 0; i < 3; i++) v.push_back(a[i]); // v = {1, 2, 3}
    makePermutation(3, 3, 0);
    return 0;
}