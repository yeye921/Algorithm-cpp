// 100*100 행렬의 각 행의 합, 열의 합, 대각선의 합 중 최댓값을 구하는 문제
// 일일이 다 구한다고 가정하면 ~O(n)이니까 괜찮을듯
#include <iostream>
#define max_n 100
using namespace std;
int arr[104][104];
int main(){
    for(int test_case = 1; test_case <= 10; test_case++){
        int ret = 0; // 최대값 갱신할 변수
        fill(&arr[0][0], &arr[0][0] + 104*104, 0);

        int T;
        cin >> T;

        // 각 행의 합 계산
        for(int i = 0; i < max_n; i++){
            int row = 0;
            for(int j = 0; j < max_n; j++){
                int num;
                cin >> num;
                arr[i][j] = num;
                row += arr[i][j];
            }
            ret = max(ret, row);
        }
        // 각 열의 합 계산
        for(int i = 0; i < max_n; i++){
            int col = 0;
            for(int j = 0; j < max_n; j++){
                col += arr[j][i];
            }
            ret = max(ret, col);
        }
 

        // 좌측/우측 대각선의 합 계산
        int left = 0;
        int right = 0;
        for(int i = 0; i < max_n; i++){
            left += arr[i][i];
            right += arr[i][max_n-1-i];
        }
        ret = max(ret, left);
        ret = max(ret, right);
        cout << "#" << T << " " << ret << "\n";
    }
}