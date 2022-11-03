// m1) Permutation 이용 (9P7 = 18만, 천만이하 => 가능) => next_permutation 이용
// 순열 = 배열의 순서가 바뀐다 => 앞에서 부터 7개 더하면 OK
#include <bits/stdc++.h>
using namespace std;
int a[9];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 9; i++){
        cin >> a[i];
    }
    sort(a, a + 9); // 오름차순 정렬 (for next_permutation)
    
    // 순열을 만들 범위가 배열 전체임 => 전체 배열의 순서 바꿈
    do{
        int sum = 0;
        for(int i = 0; i < 7; i++) sum += a[i]; // 앞에서 부터 7개 더함
        if(sum == 100) break; // 합이 100이 되면 빠져나감
    }while(next_permutation(a, a + 9)); 

    for(int i = 0; i < 7; i++) cout << a[i] << "\n";
    return 0;
}