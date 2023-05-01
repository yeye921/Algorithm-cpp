// 주어진 퍼즐 모양에서 특정 길이 k를 갖는 단어가 들어갈 수 있는 자리의 수를 출력하는 문제
// 생각보다 조금 많이 어렵다..
// 가로나 세로에서 연속으로 길이 k 인것의 개수를 세면 됨
// 2차원 배열을 행기준, 열기준으로 2번 탐색함
#include <iostream>
using namespace std;
int T, test_case;
int n, k, num, len;
int a[18][18];
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        int ret = 0;
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> num;
                a[i][j] = num;
            }
        }
        // cout << "------------\n";
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << a[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // 2차원 배열 탐색 (행기준)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == 1) {
                    len++;
                    if(j == n - 1){ // 행의 마지막이 1로 끝날 때의 처리
                        // cout << i << " " << j << " ";
                        // cout << "len: " << len << "\n";
                        if(len == k) ret++;
                        len = 0;
                    }
                }
                else {
                    // cout << i << " " << j << " ";
                    // cout << "len: " << len << "\n";
                    if(len == k) ret++; 
                    len = 0;
                }
            }
        }
        // 2차원 배열 탐색 (열기준)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[j][i] == 1){
                    len++;
                    if(j == n - 1){
                        if(len == k) ret++;
                        len = 0;
                    }
                }
                else {
                    if(len == k) ret++;
                    len = 0;
                }
            }
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}