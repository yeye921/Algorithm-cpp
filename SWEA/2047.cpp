// 입력으로 주어진 문장에 모든 소문자 알파벳을 찾아 대문자로 변환한 다음, 그 결과를 출력하는 문제
// m1) 아스키코드 이용 => 소문자(65~90), 대문자(97~122)
// m2) 라이브러리 함수 이용 (대소문자 판별: islower(str[i]), isupper(str[i]), 대소문자 변환: tolower(str[i]), toupper(str[i])) => #include <cctype>
#include <iostream>
using namespace std;
string str;
int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 97 && str[i] <= 122){ // 소문자이면, 대문자로 변환 (97대신 'a', 122대신 'z'로도 가능)
            str[i] -= 32;
        }
    }
    cout << str << "\n";
}
/* m2)
	for(int i = 0; i < str.length(); i++){
        if(islower(str[i]){
        	str[i] = toupper(str[i]);
        }
    }
*/