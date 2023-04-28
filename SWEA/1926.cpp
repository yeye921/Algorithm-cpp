// 1 ~ N까지의 숫자를 게임 규칙에 맞게 출력해라
// 3,6,9가 들어가 있는 수는 말하지 않고 대신 박수를 친다(-)
#include <iostream>
using namespace std;
int n;
string ret;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        // 각자리 숫자가 3,6,9 중 하나인지 확인해야함 (문자열로 변환한 뒤 각 글자를 확인)
        string num = to_string(i);
        int size = num.length();
        string clap = "";
       
        for(int j = 0; j < size; j++){
            if(num[j] == '3' || num[j] == '6' || num[j] == '9'){
                clap += "-";
            }
        }
        if(clap.size()) ret += clap + " ";
        else ret += num + " ";
    }
    cout << ret << "\n";
}