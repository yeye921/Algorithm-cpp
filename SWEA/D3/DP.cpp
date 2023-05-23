// DP(다이나믹 프로그래밍)을 이용한 문제
// problem과 subproblem으로 나눔
// 우리가 찾아야되는 문제는 각각의 물건이 배낭에 "있는 경우"와 "없는 경우"를 생각해야함
// 따라서 NS("ABCD", 5)는 D가 있는 경우와 없는 경우로 다음과 같이 나눌 수 있다
// => 1. NS("ABC", 1), 2. NS("ABC", 5)
 

// 다이나믹 프로그래밍이란 하나의 문제를 단 한번만 풀도록 하는 알고리즘이다.
// 다이나믹 프로그래밍은 다음의 가정 하에 사용할 수 있다.
// 가정1. 큰 문제를 작은 문제로 나눌 수 있다
// 가정2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다
// => 즉, 크고 어려운 문제가 있으면 그것을 먼저 잘게 나누어서 해결한 뒤에 처리하여 나중에 전체의 답을 구하는 것이다
// 이 과정에서 메모이제이션(=이미 구한 답을 잠시 기록해두는 과정)이 사용된다는 점에서 분할 정복과 다르다.

// 이렇게 dp를 이용하면 시간복잡도는 O(n)이 된다.
#include <iostream>
using namespace std;
int d[100]; // 결과(이미 구한 값)를 담을 배열

int dp(int x){
    if(x == 1) return 1;
    if(x == 2) return 1;
    if(d[x] != 0) return d[x]; // 이미 구한 값이라면, 구한 값 자체를 반환함 (메모이제이션)
    return dp(x - 1) + dp(x - 2);
}
int main(void){
    cout << dp(50) << "\n";
}

// 예제2
// DP는 어떤 문제의 규칙성을 찾아서, 점화식을 세우는게 가장 중요하다
// 문제: 2xn 크기의 직사각형을 1x2, 2x1 타일로 채우는 방법의 수를 구하는 프로그램을 작성해라
// 모든 경우의 수는 1*2크기의 직사각형을 세로로 1개 넣거나 2*1크기의 직사각형을 가로로 2개 넣거나로 나눌 수 있다 
// 점화식 : D[n] = D[n-1] + D[n-2]

// 추가 설명
// d[n-1] + 1x2 조합 하나가 d[n] 구성하는 조합중 하나가 되고
// d[n-2] + 2x1 2개 조합 하나가 d[n] 구성하는 두번째 조합이 됩니다.
// 두 조합은 오른쪽 모양이 다르기 때문에 서로 중복되지 않고요. 두 조합의 갯수는 오른쪽은 고정이니 각각 d[n-1], d[n-2]랑 같아서 d[n]=d[n-1] + d[n-2] 가 되네요.
int d[1001]; // n의 길이는 최대 1000
int dp(int x){
    // 재귀함수 종료조건
    if(x == 1) return 1; // 길이가 1일때는 1개의 경우 존재
    if(x == 2) return 2; // 길이가 2일때는 2개의 경우 존재
   
    // 이미 특정한 값을 구했다면 그 값을 그대로 반환해줌
    if(d[x] != 0) return d[x];  // d[x]: 길이가 x일때 총 경우의 수를 의미함
    // 그렇지않다면, 메모이제이션 기법을 통해 새롭게 구한 값을 저장해줌
    return d[x] = (dp(x - 1) + dp(x - 2));
}
int main(){
    int x;
    cin >> x;
    cout << dp(x) << "\n";
}

// 예제3 
// 2xn 직사각형을 2x1과 2x2 타일로 채우는 방법의 수를 구하는 프로그램을 작성해라
// 따라서, 직사각형 모양은 1x2, 2x1, 2x2으로 총 3가지가 존재한다 (2x1을 돌리면 1x2니까 2개다됨)
// 1. 가로로 길이 1의 직사각형이 들어갈 경우의 수는 1가지이다 (나머지 길이는 n-1)
// 2. 가로로 길이 2의 직사각형이 들어갈 경우의 수는 2가지이다 (2x2로 1개, 2x1로 2개) (나머지 길이는 n-2)
// => 이렇게 총 3가지 경우의 수가 존재한다
// 점화식: D[n] = D[n-1] + 2*D[n-2]

int d[1001]; // n의 길이는 최대 1000
int dp(int x){
    // 재귀함수 종료조건
    if(x == 1) return 1; // 길이가 1일때는 1개의 경우 존재
    if(x == 2) return 3; // 길이가 2일때는 총 3가지 경우의 수 존재 (1x2로 2개, 2x1로 2개, 2x2로 1개) (중요!)
   
    // 이미 특정한 값을 구했다면 그 값을 그대로 반환해줌
    if(d[x] != 0) return d[x];  // d[x]: 길이가 x일때 총 경우의 수를 의미함
    // 그렇지않다면, 메모이제이션 기법을 통해 새롭게 구한 값을 저장해줌
    return d[x] = (dp(x - 1) + 2 * dp(x - 2));
}
int main(){
    int x;
    cin >> x;
    cout << dp(x) << "\n";
}