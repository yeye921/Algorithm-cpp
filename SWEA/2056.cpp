// 8자리 날짜를 입력받고 유효성 판단하는 프로그램
// 월에 따른 일의 유효성만 판단하면 됨
#include <iostream>
using namespace std;
int test_case;
int month, day;
string s;
bool flag;
int main(){
    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        cin >> s;
        month = stoi(s.substr(4, 2));
        day = stoi(s.substr(6));
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 12){
            if(day < 1 || day > 31) flag = false;
            else flag = true;
        }
        else if(month == 4 || month == 6 || month == 9 || month == 10 || month == 11){
            if(day < 1 || day > 30) flag = false;
            else flag = true;
        }
        else if(month == 2) {
            if(day < 1 || day > 28) flag = false;
            else flag = true;
        }
        else flag = false;
        if(!flag) cout << "#" << test_case << " -1\n";
        else {
            s.insert(4, "/");
            s.insert(7, "/");
            cout << "#" << test_case << " " << s << "\n";
        }
    }
}