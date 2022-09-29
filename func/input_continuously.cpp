// 입력이 계속해서 이어질 때 사용
// 입력 개수가 주어지지 않고 입력이 끝날 때까지 입력 받아야 될 때

// sol 1) scanf로 할 때
// #include <bits/stdc++.h>
// using namespace std;
// int n;
// int main(){
//     while(scanf("%d", &n) != EOF){
//         cout << 1 << '\n';
//     }
//     cout << "end";
//     return 0;
// }

// so1 2) cin으로 할 때
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    while(cin >> n){
        cout << 1 << '\n';
    }
    cout << "end";
}