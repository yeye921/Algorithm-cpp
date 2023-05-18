// 구현으로 품
/* 이 예제 적용해서 수정해보기
7
1 0 2 0 1 0 1
0 2 0 0 0 0 0
0 0 1 0 0 1 0
0 0 0 0 1 2 2 
0 0 0 0 0 1 0  
0 0 2 1 0 2 1
0 0 1 2 2 0 2
*/
#include <iostream>
using namespace std;
#define max_n 104
int len;
int ret;
int arr[max_n][max_n];
bool visited[max_n][max_n];
void move_down(int y, int x){
    visited[y][x] = 1; // 방문 처리

    for(int next_y = y + 1; next_y < len; next_y++){
        if(arr[next_y][x] == 1){ // 같은 n극 자성체를 만나면, 종료해야함 (중요, in 4열)
            return;
        }
        if(arr[next_y][x] == 2){ // s극 자성체를 만나면
            ret++;               // 교착 +1
            visited[next_y][x] = 1;
            return;
        }
    }
    return;
}
int main(){
    for(int test_case = 1; test_case <= 10; test_case++){
        ret = 0;
        fill(&arr[0][0], &arr[0][0] + max_n * max_n, 0);
        memset(visited, 0, sizeof(visited));

        cin >> len; // 이 값은 항상 100
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                int num;
                cin >> num;
                arr[i][j] = num;
            }
        }
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){ // 색깔에 따라 이동방향이 달라짐 
                // 방문 여부 확인함
                if(arr[i][j] == 1 && !visited[i][j]) move_down(i, j);
            }
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}