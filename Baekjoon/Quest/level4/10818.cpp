// 주어진 수열에서 최댓값과 최솟값 구하는 문제
// m0) 중요! 가장 쉬운 방법 => 배열에 입력값들을 집어넣고 오름차순 정렬후 가장 앞, 뒤 숫자가 최소, 최대값이다!!
// m1) 수열을 입력받으면서 최소, 최대값 갱신
// m2) max_element, min_element() 이용
#include <bits/stdc++.h>
using namespace std;
int n, num;
int mx = -1000000, mn = 1000000 ; // 최소값은 최대값부터, 최대값은 최소값부터 갱신해나감
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){ // 중요! 입력받으면서 갱신해나기기 때문에 굳이 배열에 입력받은 정수를 저장하여 메모리 낭비할 필요가 없음!!
        cin >> num;
        mx = max(mx, num);
        mn = min(mn, num);
        /* 이런식으로도 가능
        if(num > mx) mx = num;
        else if(num < mn) mn = num
        */
    }
    cout << mn << " " << mx << "\n";
    return 0;
}