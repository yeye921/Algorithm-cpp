// 숫자타입체크: n이 최대 7이므로 나올수 있는 숫자의 최대자리수는 7자리이다 => int로도 가능
// 배열을 회전시키고 그 배열을 압축?해서 누적하는 과정이 필요함
#include <iostream>
#include <cstring>
using namespace std;
int T, test_case;
int n, num;
int arr1[10][10], arr2[10][10];
string ret[8][8]; // 최종 결과를 저장할 배열
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        memset(arr1, 0, sizeof(arr1));
        memset(arr2, 0, sizeof(arr2));
        memset(ret, 0, sizeof(ret));

        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> num;
                arr1[i][j] = num;
            }
        }
        // 배열 회전시키기 (90도)
        int idx = 0;
        while(idx != 3){
            for(int i = 0; i < n; i++){
                string s = "";
                for(int j = 0; j < n; j++){
                    arr2[i][j] = arr1[n-1-j][i]; 
                    s += to_string(arr1[n-1-j][i]); // 배열 압축해서 누적함
                }
                ret[i][idx] = s;
            }
            idx++;
            memcpy(arr1, arr2, sizeof(arr2)); // arr2 = arr1으로 설정
        }

        cout << "#" << test_case << "\n";
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << arr2[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "ret -----\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                cout << ret[i][j] << " ";
            }
            cout << "\n";
        }
    }
}