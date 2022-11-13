#include <bits/stdc++.h>
using namespace std;
int v[10];
int main(){
    for(int i = 1; i <= 10; i++) v[i - 1] = i;
    for(int a : v) cout << a << " ";
    
    auto a = find(v, v + 10, 100);
    if(a == v + 10) cout << "not found" << "\n";
    fill(v, v + 10, 10);

}
