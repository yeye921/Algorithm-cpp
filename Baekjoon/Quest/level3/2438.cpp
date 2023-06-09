#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        // i번만큼 별을 찍음
        for(int cnt = 0; cnt < i; cnt++) cout << "*";
        cout << "\n";
    }
}