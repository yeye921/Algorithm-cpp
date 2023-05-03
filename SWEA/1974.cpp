#include <iostream>
#include <cstring>
using namespace std;
 
int map[10][10];
//각각의 행,열,3X3칸에 대해 1~9숫자가 있는지 판별
bool check[3][10][10];
 
int main() {
    int test_case;
    int T;
    cin >> T;
 
    for (test_case = 1; test_case <= T; test_case++) {
        memset(check, false, sizeof(check));
 
        //입력
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cin >> map[i][j];
 
                //i행에 입력된 숫자(map[i][j]) = true
                check[0][i][map[i][j]] = true;
                //j열에 입력된 숫자 = true
                check[1][j][map[i][j]] = true;
                
                //3X3칸에 입력된 숫자 = true
                int index = ((i - 1) / 3 * 3) + 1 + (j - 1) / 3;
                check[2][index][map[i][j]] = true;
            }
        }
 
        //check배열이 모두 true로 되어있는지 확인
        int res = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= 9; j++) {
                for (int k = 1; k <= 9; k++) {
                    if (!check[i][j][k]) {
                        res = 0;
                    }
                }
            }
        }
 
        //출력
        cout << "#" << test_case << " " << res << "\n";
    }
}