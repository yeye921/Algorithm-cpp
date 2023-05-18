// 문어박사 풀이 => (내 풀이보다 1000ms 빠름)
// DFS 이용
// 선택할거냐/말거냐를 결정하는 대표적인 문제
#include <iostream>
#include <vector>
using namespace std;
int T;
int n, k;
int ret;
int arr[23];
void dfs(int idx, int sum){
    if(idx == n){ // 기저사례 (숫자 n개에 대해 선택할지/말지 모두 결정했으면 종료)
        if(sum == k) ret++;
        return;
    }
    dfs(idx + 1, sum + arr[idx]); // idx번째 요소를 선택하는 경우
    dfs(idx + 1, sum);            // idx번째 요소를 선택하지 않는 경우
}
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        fill(arr, arr + 23, 0);
        ret = 0;
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            arr[i] = num;
        }
        dfs(0, 0);
        cout << "#" << test_case << " " << ret << "\n";
    }
}