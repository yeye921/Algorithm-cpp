// 시작에서 끝으로 도는 것이 아니라 끝에서 시작으로 돌아야 해결되는 문제다.
// N-1부터 0으로 돌면서, num[N-1]보다 작은 값일 때는 산다고 가정하고,
// num[N-1]보다 큰 값일때는 값을 변경해주면 된다.
#include <iostream>
using namespace std;
int num[1000002] = {0,};
int main(){
    int T;
    cin>>T;
    
    for(int i = 0; i<T; i++){
        int N;
        long long ans = 0;
        
        cin >> N;
        for(int j = 0; j<N; j++){
            cin >> num[j];
        }
        
        int max_budget = num[N-1];
        
        for(int j = N - 1; j >= 0; j--){
            if(max_budget >= num[j]){
                ans = ans + (max_budget - num[j]);
            }
            else{
                max_budget = num[j];
            }
        }
        cout << "#" << i + 1 << " " << ans << "\n";
        for(int j = 0; j < N; j++){
            num[j] = 0;
        }  
    }
    return 0;
}


