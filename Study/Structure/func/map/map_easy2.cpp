// 아래 코드처럼 map은 해당 인덱스에 참조만 해도 맵에 값이 생기며 맵의 요소가 생성된다
// int형의 경우 0으로, string의 경우 빈문자열로 들어가게 된다.
#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
map<string, string> mp2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << mp[1] << "\n";       // 0
    cout << mp2["aaa"] << "\n";  // ""

    for(auto i : mp) cout << i.first << " " << i.second;  // 1 : 0
    cout << "\n";

    for(auto i : mp2) cout << i.first << " " << i.second; // aaa : "" 
    cout << "\n";
    return 0;
}

/* 추가
ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
위 코드를 사용하게 되면 C와 C++사이의 stream 동기화를 끊는다.
동기화를 끊음으로서 C++ stream들은 독립적인 buffer를 갖게되고
buffer의 수가 줄어들며 속도가 빨라지게 된다.
*/