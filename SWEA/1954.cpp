// 정수 n을 입력 받아, N크기의 달팽이 출력하기
// 달팽이 풀이 1) 재귀 함수 이용 
// ex. 4*4 -> 2*2 -> 1*1로 쪼개서 겉 테두리만 채우면 됨

#include <iostream>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int T, test_case;
int n;
int _map[13][13];
// 재귀함수
void recursion(){
    // 여기서 쪼개고 어쩌고 ...
}
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        fill(&_map[0][0], &_map[13][13], 0); // 2차원 배열 초기화
        cin >> n;
        int size = n;
        int num = 1;
        int start = 0;
        // 일단 겉 테두리만 돌기 (0행, n-1열, n-1행, 0열)
        while(size != 1){
            // 0행 (x+1)
            for(int i = start; i < n; i++){
                if(!_map[start][i]){ // 값이 비어있을 때만 실행함
                    _map[start][i] = num;
                    num++;
                }
            }
            // n-1열 (y+1)
            for(int i = start; i < n; i++){
                if(!_map[i][n-1]){ // 값이 비어있을 때만 실행함
                    _map[i][n-1] = num;
                    num++;
                }
            }
            // n-1행 (x-1)
            for(int i = n-1; i >= start; i--){
                if(!_map[n-1][i]){
                    _map[n-1][i] = num;
                    num++;
                }
            }
            // // 0열 (y-1)
            for(int i = n-1; i >= start; i--){
                if(!_map[i][start]){
                    _map[i][start] = num;
                    num++;
                }
            }
            size /= 2;
            start++;
        }

        cout << "#" << test_case << "\n";
        // 달팽이 출력
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << _map[i][j] << " ";
            }
            cout << "\n";
        }
    }
}