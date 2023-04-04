// N바이트 정수까지 저장할 수 있다고 생각하는 정수 자료형의 이름을 출력
// int앞에 long을 하나씩 더 붙일때마다 4바이트씩 저장할 수 있는 공간이 늘어난다
// +) long int: 4바이트 정수까지 저장할 수 있는 정수 자료형
// +) long long int: 8바이트 정수까지 저장할 수 있는 정수 자료형
#include <bits/stdc++.h>
using namespace std;
int n;
string ret="long int";
int main(){
    cin >> n;
    int cnt = n / 4;
    for(int i = 1; i < cnt; i++){
        ret = "long " + ret;
    }
    cout << ret << "\n";
    return 0;
}