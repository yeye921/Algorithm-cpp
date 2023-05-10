// 초기 속도는 0이고 가속도를 입력받을때마다 속도에 가속도를 더하면 현재속도가 됨
// 현재 속도가 현재 이동거리가 됨
#include <iostream>
using namespace std;
int T;
int n;
int command, velocity;
int ret;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin >> n;
        ret = 0;
        int x = 0;
        for(int i = 0; i < n; i++){
            cin >> command;
            if(command == 1){
                cin >> velocity;
                x += velocity;

            }else if(command == 2){
                cin >> velocity;
                if(velocity > x) x = 0;
                else x -= velocity;
            }
            ret += x; // 매초마다 이동거리를 누적함
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}