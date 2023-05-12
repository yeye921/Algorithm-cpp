#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int T;
int n, num;
int arr[104];
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        memset(arr, 0, sizeof(arr));
        int up = 0;
        int down = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> num;
            arr[i] = num;
        }
        for(int i = 0; i < n-1; i++){
            if(arr[i] < arr[i + 1]){ // up의 경우
                up = max(up, arr[i+1] - arr[i]);
            } else if(arr[i] > arr[i+1]){
                down = max(down, arr[i] - arr[i+1]);
            }
        }
        cout << "#" << test_case << " " << up << " " << down << "\n";
    }
}