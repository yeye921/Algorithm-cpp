// a와 b가 가위바위보를 했을때 누가 이겼는지 판별하는 문제 (비기는 경우는 없음)
// 가위: 1, 바위: 2, 보: 3 
// 비기는 경우를 제외한 가위바위보의 모든 경우의 수 => 3 * 2 = 6
// 6개 경우의 수에 대한 처리를 해줘야 함
#include <iostream>
using namespace std;
int a, b;
char ret;
int main(){
    cin >> a >> b;
    if(a == 1){
        if(b == 2) ret = 'B'; 
        else if(b == 3) ret = 'A';
    }
    else if(a == 2){
        if(b == 1) ret = 'A';
        else if(b == 3) ret = 'B';
    }
    else {
        if(b == 1) ret = 'B';
        else if(b == 2) ret = 'A';
    }
    cout << ret << "\n";
    return 0;
}