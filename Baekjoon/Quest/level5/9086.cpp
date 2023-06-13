#include <bits/stdc++.h>
using namespace std;
int T;
string str;
int main(){
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> str;
        cout << str[0] << str[str.size() - 1] << "\n"; // size함수 대신 length함수도 가능
    }
}