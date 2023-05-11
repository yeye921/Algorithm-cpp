// 양쪽 모두 거리 2이상의 공간이 확보될 때 조망권이 확보된다
// => 즉, a의 좌우로 2칸이내 건물에 a보다 높은 건물이 없다는 뜻
#include <iostream>
#include <cstring>
using namespace std;
int n, height;
int buildings[1004];
const int dx[4] = {-2, -1, 1, 2}; // 현재 좌표로부터 이동할 x좌표
int main(){
    for(int test_case = 1; test_case <= 10; test_case++){
        memset(buildings, 0, sizeof(buildings));
        int ret = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> height;
            buildings[i] = height;
        }
        for(int i = 2; i < n - 2; i++){
            int a = buildings[i];
            while(1){
                bool flag = 1;
                // 좌우 2칸이내 건물에 a보다 높은 건물이 있는지 확인
                for(int j = 0; j < 4; j++){
                    if(buildings[i + dx[j]] >= a){
                        flag = 0;
                        break;
                    }
                }
                // 각 건물의 맨 위층의 조망권이 확보되면 그 아래층도 그때 검사하는식
                if(flag){
                    ret++;
                    a--;
                }
                else break;
            }
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}