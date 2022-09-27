#include <bits/stdc++.h>
using namespace std;
int ret = 1;
void a(){      /* void 함수는 아무것도 리턴하지 않음 */
    ret = 2;
    cout << ret << "\n";
    return;
}
int main(){
    a();
    return 0;
}
