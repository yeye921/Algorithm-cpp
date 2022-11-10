// 순열을 이용해서 풀어보자
#include <bits/stdc++.h>
using namespace std;
int a[9], sum;
vector<int> v;
int main(){
    for(int i = 0; i < 9; i++)
        cin >> a[i];

    sort(a, a + 9); // 오름차순 정렬 for next_permutation

    do{
        int sum = 0;
        for(int i = 0; i < 7; i++) sum += a[i];
        if(sum == 100) break;
    }while(next_permutation(a, a + 9)); // 배열 a의 순서를 바꿈

    for(int i = 0; i < 7; i++) cout << a[i] << "\n";
    return 0;
}