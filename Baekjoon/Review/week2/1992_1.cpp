// 문자 -> 문자열 변환: string(int size, char c)
// int -> 문자열 변환: to_string(int n);

// 이상하게 틀리는 경우
// ret을 전역변수로 선언하고 2중for문 탐색전에 초기화하는 경우
// 반대로 그냥 string ret = "";으로 하면 아무문제 없음
#include <bits/stdc++.h>
using namespace std;
int n;
int a[65][65];
string s;
string quard(int y, int x, int size){ // 재귀함수
    // cout << y << " : " << x << " : " << size << " : " << ret <<  "\n";
    if(size == 1) return to_string(a[y][x]); // 기저사례: 크기가 1이면 해당 원소 반환
    char b = a[y][x]; // 비교대상
    string ret = ""; // !!!!!!!!! 왜????
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
                return ret; // !! 여기서 문자열 저장한 ret을 리턴처리해줘야함 (아니면 아래 리턴문으로 나감)
            }
        }
    }
    // 전체 탐색 결과, 모두 같은 값을 갖는다면
    return to_string(a[y][x]);
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
    cout << quard(0, 0, n) << "\n";
    return 0;
}