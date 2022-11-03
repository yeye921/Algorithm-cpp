// m2) combination 이용 (9C7 = 9C2)
// 다음과 같은 로직 이용
// 전체 난쟁이 키의 합 = 일곱 난쟁이 합(=100) + 두 난쟁이(우리가 뽑은 것)
// 즉, 전체 난쟁이 키의 합 - 두 난쟁이 = 일곱 난쟁이 합(=100)
#include <bits/stdc++.h>
using namespace std;
int a[9], sum;
vector<int> v;
pair<int, int> ret; // 2개 원소를 저장하는 자료구조
void solve(){
    // 9개 중 2개 뽑는 경우의 수
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if(sum - a[i] - a[j] == 100){
                ret = {i, j}; // 값 자체가 아니라 인덱스로 저장함
                return;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 9; i++){
        cin >> a[i];
        sum += a[i]; // sum = 전체 난쟁이 키의 합
    }
    solve();
    
    // 우리가 구한 이상한 두 난쟁이(ret)를 배열에서 제외시켜줌
    for(int i = 0; i < 9; i++){
        if(i == ret.first || i == ret.second) continue; // 찾은 인덱스로 제거시켜줌
        v.push_back(a[i]); // 일곱 난쟁이만 벡터에 저장시켜줌
    }

    // 오름차순 정렬 뒤 출력 시켜줌 
    sort(v.begin(), v.end());
    for(int i : v) cout << i << "\n";

    return 0;
}