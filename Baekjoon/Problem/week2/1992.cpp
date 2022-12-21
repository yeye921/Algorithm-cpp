// 분할정복  & 재귀 문제
// 인자들이 수정되지만 똑같은 로직이 반복될 때 => 재귀함수 이용 !!
// 재귀함수는 메인로직과 기저사례로 구성된다
// 영역이 4개로 나누어지기 때문에 go라는 재귀함수 안에서 go가 4번 호출된다

// 주요 알고리즘
// 1. 해당 범위의 모든 원소가 같은지 확인
// 2. 아닐경우 4등분하고 1로 돌아감

// +) 숫자 문자를 숫자로 변환하는 법: a[i][j] = s[j] - '0' (atoi는 문자열이 숫자인지 판단할 때 사용)
// +) char to string: string(int size, char c)
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char a[65][65]; // int형 배열이 아니라 char형 배열로 해도 괜찮음
string quard(int y, int x, int size){
    cout << y << " : " << x << " : " << size << "\n";
    if(size == 1) return string(1, a[y][x]); // 재귀함수의 필수조건 = 기저사례 (탐색영역 크기가 1이면 그 숫자를 반환)
    char b = a[y][x]; 
    string ret = "";
    // 영역이 4개 => 재귀함수 안에서 같은 재귀함수가 4번 호출됨
    // 이 함수들은 영역이 계속 줄어들으면서 쪼개짐
    for(int i = y; i < y + size; i++){ // (중요!!) 이렇게 스타트 좌표(x1, y1)로 부터 size만큼으로 범위 잡는게 편함 (x1, y1, x2, y2 이렇게 4개 좌표 입력받을수도 있지만 불편함)
        for(int j = x; j < x + size; j++){
            if(b != a[i][j]){ // 해당 범위의 원소가 모두 같지 않다면
                ret += '('; // 4개 영역으로 쪼개지는 것에 대해서 괄호 처리
                // 사이즈를 줄여가면서 탐색
                ret += quard(y, x, size / 2); // 왼쪽 위 영역
                ret += quard(y, x + size / 2, size / 2); // 오른쪽 위 영역
                ret += quard(y + size / 2, x, size / 2); // 왼쪽 아래 영역
                ret += quard(y + size / 2, x + size / 2, size / 2); // 오른쪽 아래 영역
                ret += ')';
                // cout << ret << "\n";
                return ret;
            }
        }
    }
    return string(1, a[y][x]); // 모두 같다면 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = s[j];
        }
    }
    cout << quard(0, 0, n) << "\n"; // (0, 0)에서 시작
    return 0;
}