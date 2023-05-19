// 높이가 B 이상인 탑 중에서 높이가 가장 낮은 탑을 구해라 (최소값 갱신)
// => N명의 점원에 대해서 뽑을지/말지 결정해야함
// m1) dfs 이용 (비트마스킹을 이용한 완전탐색보다 더 효율적임)
#include <iostream>
using namespace std;
int T;
int n, b;
int arr[23];
int ret;
void dfs(int idx, int sum){
    if(idx == n){  // 기저사례 
        if(sum >= b){
            ret = min(ret, sum-b); // 높이가 b이상이면서 최소가 되게해야함
        }
        return;
    }
    dfs(idx+1, sum+arr[idx] ); // 해당 idx번째 점원을 선택함
    dfs(idx+1, sum);           // 해당 idx번째 점원을 선택하지 않음
    return;
}
int main(){
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        ret = 200000;
        fill(arr, arr + 20, 0);

        cin >> n >> b;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        // N명의 점원에 대해서 뽑을지/말지 결정해야함
        dfs(0, 0);
        cout << "#" << tc << " " << ret << "\n";
    }
}