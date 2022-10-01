#include <bits/stdc++.h>
using namespace std;
int v[10];  // 10개의 원소를 가지는 배열 v 선언
int main(){
    for(int i = 1; i <= 10; i++) v[i-1] = i;  // v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    for(int a : v) cout << a << " ";
    cout << "\n";

    auto a = find(v, v + 10, 100); // 여기서 v가 뭐임???
    if(a == v + 10) cout << "not found" << "\n";
    
    fill(v, v + 10, 10); 
    for(int a : v) cout << a << " ";
    cout << "\n";
    return 0; 
    }
