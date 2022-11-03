// lower_bound 함수와 upper_bound 함수
// : 이분탐색을 함수로 쉽게 구현하는 함수
// : 정렬된 배열에서 어떤 값이 나오는 지점 OR 어떤 값이 나오기 전의 위치를 반환하는 함수

// lower_bound(): 어떠한 값의 "이상이 되는 위치"를 반환함
// upper_bound(): 뒤에서부터 탐색하면서 "그 값이 시작되기 전의 위치"를 반환함
// 둘다 이터레이터를 반환함

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> v;
    int a[5] = {1, 2, 2, 2, 3}; 
    for(int i = 0; i < 5; i++){
        v.push_back(a[i]);
    }
    int x = 2;
    int c = (int)(upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x)); // (a+4)-(a+1) = 3
    int f = (int)(lower_bound(v.begin(), v.end(), x) - v.begin()); // (a+1)-(a) = 1
    int t = (int)(upper_bound(v.begin(), v.end(), x) - v.begin()); // (a+4)-(a) = 4

    int f2 = *lower_bound(v.begin(), v.end(), x); // *(2가 나오는 지점): *(a+1) = 2
    int t2 = *upper_bound(v.begin(), v.end(), x); // *(2가 나오기 전의 위치): *(a+4) = 3

    printf("%d 의 갯수: %d, 시작되는 점: %d 끝나는 점: %d\n", x, c, f, t);
    printf("lower_bound가 시작되는 점의 값 : %d, upper_bound가 시작되는 점의 값: %d\n", f2, t2);

    // v.begin(), v.end()를 a와 a+5로 교체해도 결과 똑같음 (그냥 배열의 시작주소, 끝주소+1 만 들어가면 됨)
    c = (int)(upper_bound(a, a + 5, x) - lower_bound(a, a + 5, x));
    f = (int)(lower_bound(a, a + 5, x) - a);
    f2 = *lower_bound(a, a + 5, x);
    t2 = *upper_bound(a, a + 5, x);

    printf("%d의 갯수: %d, 시작되는 점: %d 끝나는 점: %d\n", x, c, f, t);
    printf("lower bound가 시작되는 점의 값: %d, upper bound가 시작되는 점의 값: %d\n", f2, t2);

    return 0;
}
