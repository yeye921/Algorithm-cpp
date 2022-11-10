#include <bits/stdc++.h>
using namespace std;
// 1. 순열 2. 조합
int a[9], sum;
pair<int, int> ret; // pair는 두 인자에 대해 모두 형 선언을 해줘야 함
vector<int> v;
void solve(){
    for(int i = 0; i < 9; i ++){
        for(int j = i + 1; j < 9; j++){ // j는 i 다음부터 시작함
            // 두명 뽑음
            // 만약 두 명 키의 합이 (총 키 - 100)이면 끝!
            if(a[i] + a[j] + 100 == sum){
                // 이 두개를 난쟁이에서 제외시킴..?
                ret = {i, j}; // 두 난쟁이의 인덱스를 저장함
            }
        }   
    }
}
int main(){
    for(int i = 0; i < 9; i++){
        cin >> a[i];
        sum += a[i];
    }

    solve();
 
    for(int i = 0; i < 9; i++){
        if(i == ret.first || i == ret.second) continue; // 인덱스로 제외시킴
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    for(int i : v) cout << i << "\n";
    
    return 0;
}