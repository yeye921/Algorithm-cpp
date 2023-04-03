// 목표: 오븐구이가 끝나는 시각 계산하기
#include <bits/stdc++.h>
using namespace std;
int A, B, C, hour, min;
int main(){
    cin >> A >> B;
    cin >> C;
    int hour = A + ((B + C) / 60); 
    int min = (B + C) % 60;
    if(hour >= 24) hour %= 24; // 23시 다음은 24시가 아니라 0시이다
    cout << hour << " " << min << "\n";
    return 0; 
}