#include <iostream>
#include <climits>
#include <algorithm>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n,m;
        cin >> n >> m;
         
        int arr[n][n];
         
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> arr[i][j];
            }
        }
         
        int MAX = INT_MIN;
        for(int i=0;i<n-m+1;i++){
            for(int j=0;j<n-m+1;j++){
                 
                int sum = 0;
                for(int r=0;r<m;r++){
                    for(int c=0; c<m;c++){
                        sum+=arr[i+r][j+c];
                    }
                }
                 
                MAX = max(MAX, sum);
            }
        }
         
        cout << "#" << test_case <<" " << MAX << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}