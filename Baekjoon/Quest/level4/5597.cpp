// m1) 배열에 저장해두고 배열값이 0이면 그 번호 출력하기
#include <bits/stdc++.h>
using namespace std;
int n;
bool arr[33];
vector<int> ans;
int main(){
    for(int i = 0; i < 28; i++){
        cin >> n;
        arr[n] = 1;
    }
    // i자체가 오름차순이기 때문에 가장 작은 것을 먼저 출력하기 위해 따로 뭐 해줄필요가 없음
    for(int i = 1; i <= 30; i++){
        if(!arr[i]){
            cout << i << "\n";
        }
    }
    return 0;
}