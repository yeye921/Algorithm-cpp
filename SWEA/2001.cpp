#include <iostream>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++)
    {
        int M, N, ans = 0, sum = 0;
        int arr[15][15];
        
        cin >> N >> M;
        
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
                cin >> arr[j][k];
        }
        
        for(int j = 0; j < N - M + 1; j++)
        {
            for(int k = 0; k < N - M + 1; k++)
            {
                sum = 0;
                for(int l = j; l < j + M; l++)
                {
                    for(int m = k; m < k + M; m++)
                        sum += arr[l][m];
                }
                if(ans < sum)
                    ans = sum;
            }
        }
        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}