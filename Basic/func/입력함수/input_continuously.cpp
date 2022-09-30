// 입력 개수가 주어지지 않고 입력이 끝날 때까지 계속 입력 받아야 될 때
/*
데이터 소스에서 더 이상 읽을 데이터가 없어 EOF(End Of File)를 리턴하면 종료
백준 알고리즘 문제 풀이 등에 사용 가능
사용자의 입력을 직접 받을 때는 사용자가 종료하기 전에는 종료X
*/

// sol 1) scanf로 할 때
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    while(scanf("%d", &n) != EOF){ // 더이상 입력받지 않을 때 탈출함
        cout << n << '\n';
    }
    cout << "end";
    return 0;
}

// so1 2) cin으로 할 때
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    while(cin >> n){
        cout << n << '\n';
    }
    cout << "end";
}