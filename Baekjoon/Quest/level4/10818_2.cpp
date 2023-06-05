// m0) sort()함수를 이용하여 배열의 최소, 최대값을 구하는 방식
#include <bits/stdc++.h>
using namespace std;
int n, arr[1000004];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n); // 이 부분 중요함!!) 0 ~ N-1 범위만 정렬해야함
    cout << arr[0] << " " << arr[n-1] << "\n";
    return 0;
}