#include<iostream>
#include <climits>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int room[1000][1000];
 
int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };
 
int MAX = INT_MIN;
int roomMAX[1000][1000];
 
void dfs(int i, int j, int n, int roomSum, int starti, int startj) {
    roomSum++;
 
    MAX = max(MAX, roomSum);
    roomMAX[starti][startj] = max(roomMAX[starti][startj], roomSum);
     
    for (int k = 0; k < 4; k++) {
        int nxti = i + di[k];
        int nxtj = j + dj[k];
 
        if (nxti >= 0 && nxti < n && nxtj >= 0 && nxtj < n) {
            if (room[nxti][nxtj] == room[i][j] + 1) {
                dfs(nxti, nxtj, n, roomSum, starti, startj);
            }
        }
    }
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        MAX = INT_MIN;
 
        int n;
        cin >> n;
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                roomMAX[i][j] = INT_MIN;
                cin >> room[i][j];
            }
        }
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, n, 0, i, j);
            }
        }
        int MIN = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(MAX== roomMAX[i][j]) MIN = min(MIN, room[i][j]);
            }
        }
 
        cout << "#" << test_case << " " << MIN<<" " <<MAX << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}