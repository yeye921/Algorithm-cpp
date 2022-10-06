// tie를 사용하지 않고 pair, tuple에 들어있는 값을 끄집어내는 방법
#include <bits/stdc++.h>
using namespace std;
pair<int, int> pi;
tuple<int, int, int> tl;
int a, b, c;
int main(){
    pi = {1, 2};

    // cin(a, b) = pi로 대체 가능
    a = pi.first;
    b = pi.second;
    cout << a << " : " << b << "\n";

    tl = make_tuple(1, 2, 3);
    a = get<0>(tl);
    b = get<1>(tl);
    c = get<2>(tl);
    cout << a << " : " << b << " : " << c << "\n";

    return 0;
}