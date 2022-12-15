// 문자열을 숫자로 바꾸는 법: stoi(문자열)
// 삼항연산자: num2 == num1 ? a++ : b++
#include <bits/stdc++.h>
using namespace std;
#define prev aaa
#define time bbb
int n, A, B, asum, bsum;
string team, time, prev;
void print(int sum){
    int min = sum / 60;
    int sec = sum % 60;
    // 10보다 작을때만 처리해주면 됨
    string m = "";
    string s = "";
    if(min < 10) m = "0" + to_string(min);
    else m = to_string(min);

    if(sec < 10) s = "0" + to_string(sec);
    else s = to_string(sec);
    cout << m << ":" << s << "\n";
}
// 단위를 초로 맞춤
int string_to_int(string s){ 
    int min = stoi(s.substr(0, 2));
    int sec = stoi(s.substr(3));
    return min * 60 + sec;
}
void go(int &sum, string prev){
    sum += string_to_int(time) - string_to_int(prev);
    // cout << sum << "\n";
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> team >> time;

        // 이긴 시간 계산
        if(A > B) go(asum, prev);
        else if(A < B) go(bsum, prev);

        // 팀 스코어 계산
        team == "1" ? A++ : B++;
        prev = time;
    }
    // 끝점 처리 !
    time = "48:00";
    if(A > B) go(asum, prev);
    if(A < B) go(bsum, prev);
    // 다시 출력형식에 맞춰서 sum들을 출력해주는 것이 필요함
    print(asum);
    print(bsum);
}