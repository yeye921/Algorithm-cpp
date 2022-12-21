#include <bits/stdc++.h>
using namespace std;
int n, x, y, size, a[65][65];
string s, ret;
string quard(int y, int x, int size){ // 재귀함수
    cout << y << " : " << x << " : " << size << " : " << ret <<  "\n";
    if(size == 1) return string(1, a[y][x]); // 기저사례: 크기가 1이면 해당 원소 반환
    int b = a[y][x]; // 비교대상
    // 해당 영역이 모두 같은 값을 갖고있는지 체크
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(b != a[i][j]){ // 모두 같은 값을 갖지 않음
                ret += '(';
                ret += quard(y, x, size / 2);
                ret += quard(y, x + size / 2, size / 2);
                ret += quard(y + size / 2, x, size / 2);
                ret += quard(y + size / 2, x + size / 2, size / 2);
                ret += ')';
                return ret; // 여기가 정말 모르겠음 !!!!!
            }
        }
    }
    // 전체 탐색 결과, 모두 같은 값을 갖는다면
    return string(1, a[y][x]);
}
int main(){
    cin >> n;
    // 2차원 좌표 입력처리
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = s[j] - '0'; // 문자를 숫자로 변환
        }
    }
    cout << quard(0, 0, n);
    return 0;
}