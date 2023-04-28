// 5만원 > 1만원 > 5천원 > .. 순으로 거슬러 줘야하기 때문에
// if와 else if가 아니라 if문의 연속으로 해야 1번 조건문 처리후 2번 조건문으로 넘어갈 수 있음
#include <iostream>
using namespace std;
int test_case, T, n;
int arr[10];
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){ // 테스트케이스 문제는 초기화가 중요함
        memset(arr, 0, sizeof(arr));
        cin >> n;
        // 5만원 > 만원 > 오천원 > 천원 > ... 순으로 거슬러줌
        if(n >= 50000){
            int div = n / 50000;
            arr[0] = div;
            n -= (div * 50000);
        } if(n >= 10000){
            int div = n / 10000;
            arr[1] = div;
            n -= (div * 10000);
        } if(n >= 5000){
            int div = n / 5000;
            arr[2] = div;
            n -= (div * 5000);
        } if(n >= 1000){
            int div = n / 1000;
            arr[3] = div;
            n -= (div * 1000);
        } if(n >= 500){
            int div = n / 500;
            arr[4] = div;
            n -= (div * 500);
        } if(n >= 100){
            int div = n / 100;
            arr[5] = div;
            n -= (div * 100);
        } if(n >= 50){
            int div = n / 50;
            arr[6] = div;
            n -= (div * 50);
        } if(n >= 10){
            int div = n / 10;
            arr[7] = div;
            n -= (div * 10);
        }
        cout << "#" << test_case << "\n";
        // 8개 숫자 출력
        for(int i = 0; i < 8; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}