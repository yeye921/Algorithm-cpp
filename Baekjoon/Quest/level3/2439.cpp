#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n-i; j++){ // n-i번 만큼 빈칸을 출력
            cout << " ";
        }
        for(int k = 0; k < i; k++){ // i만큼 별을 출력
            cout << "*";
        }
        cout << "\n";
    }
}