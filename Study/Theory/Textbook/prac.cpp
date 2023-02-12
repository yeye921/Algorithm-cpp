// 순열을 코드로 구현하는 방법 1 - 오름차순 배열 기반 next_permutation 이용
#include <bits/stdc++.h>
using namespace std;
void printV(vector<int> & v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}
int main(){
    int a[3] = {1, 2, 3};
    vector<int> v;
    for(int i = 0; i < 3; i++) v.push_back(a[i]);
    sort(v.begin(), v.end());

    do{
        printV(v);
    } while(next_permutation(v.begin(), v.end()));
}

// 순열을 코드로 구현하는 방법 2 - 재귀를 이용
int a[3] = {1, 2, 3};
vector<int> v;
void printV(vector<int> &v){
    for(int i : v) cout << i << " ";
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
int main(){ // n개중에 r개를 뽑는 방법(순서에 상관 있게)
    for(int i = 0; i < 3; i++) v.push_back(a[i]);
    makePermutation(3, 3, 0); // n, r, depth
}