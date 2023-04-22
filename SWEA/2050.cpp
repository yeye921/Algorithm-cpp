// 알파벳으로 이루어진 문자열을 입력 받아 각 알파벳을 1~26으로 변환하기 (알파벳이 대문자만 들어온다고 가정)
// 풀이: 각 알파벳에서 문자 A를 뺀다음 1을 더해주기 (A를 1로 Z를 26으로 변환해야하니까)
#include <iostream>
using namespace std;
string str;
int main(){
    cin >> str;
    for(char c : str){
        cout << c - 'A' + 1 << " ";
    }
    cout << "\n";
}