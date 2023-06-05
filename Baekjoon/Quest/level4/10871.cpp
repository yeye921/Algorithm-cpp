#include <bits/stdc++.h>
using namespace std;
int n, x, arr[10004];
int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(arr[i] < x) cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}