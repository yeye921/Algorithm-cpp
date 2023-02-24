// n진법 변환 예제 (b에 원하는 수를 넣으면 그 진법으로 변환 가능)
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n = 1000;
    int b = 11;
    while(n > 1){
        v.push_back(n % b);
        n /= b;
    }
    if(n == 1) v.push_back(1);

    reverse(v.begin(), v.end());

    for(int a : v){
        // 10진법 이상이면 문자로 변환이 필요함 (10=A, 11=B, 12=C,...)
        if(a >= 10) cout << char(a + 55); // 왜 55를 더할까? > 10+55 = 65 = 아스키코드 A
        else cout << a;
    }
    return 0;
}