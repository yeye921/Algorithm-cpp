#include <bits/stdc++.h>
using namespace std;
int n, v, ret, arr[104];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> v;
    for(int i = 0; i < n; i++){
        if(arr[i] == v) ret++;
    }
    cout << ret << "\n";
}