// 손도 못대겠는 문제
// 정말 모르겠다
#include <bits/stdc++.h>
using namespace std;
int n;
char a[23];
long long int ret = -1e18;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // m1) 괄호 없이 계산했을 때를 ret으로 두고 갱신해나감
    // m2) 아니면 ret을 최솟값(-1e18)으로 초기화해놓고 모든 경우의 수를 계산함(괄호가 없을 경우도 포함해서)

    // 괄호 개수의 경우의 수
    int size = n / 2;
    // 0개 뽑을 경우 계산
    // size = 1이면 pass => for문 진행 안함
    // size = 2이면 pass => 1개 뽑을 경우의 수 계산
    for(int i = 1; i < size; i++){ // size개수 만큼 식을 쪼갤 수 있음 => 그것들을 i개만큼 뽑는 경우의 수
        // 괄호 개수가 i개 일 때 => 이 위치의 경우의 수 까지 계산해서 
        // 0개일 경우 => 4c0 = 1개
        // 1개일 경우 => 4c1 = 4개
        // 2개일 경우 => 4c2 = 3개
    }
}