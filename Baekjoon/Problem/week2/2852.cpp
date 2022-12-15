// 문자열을 숫자로 변환하는 법: stoi(문자열)

// Tip) prev에 직전 값을 저장하여 풀기 ! 
// 시, 분, 초가 나오면 하나의 단위로 통일해주기 ! (작은 단위로 통일하는 것을 추천)

// 이런 류의 문제 많이 나오니까 풀이 기억해두는게 좋을듯 !
#include<bits/stdc++.h>
using namespace std;
#define prev a
#define time b
int n, team, A, B; 
int asum, bsum; // a와 b가 몇초만큼 이기고 있는지 카운트
string time, prev; 
// 초를 다시 분으로 바꾸기 & 포맷화
string print(int a){ 
    string d = "00" + to_string(a / 60); // 분
    string e = "00" + to_string(a % 60); // 초
    // 출력형식을 맞춰줌 ex. 7 -> 07
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);  // 뒤에서 두글자만 자름
}
// 분을 초로 바꾸기
int changeToInt(string a){
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}
void go(int &sum, string s){ 
    sum += (changeToInt(s) - changeToInt(prev)); // 현재시간 - 직전시간
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL); 

    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> team >> time; 
        if(A > B) go(asum, time); // a가 이기고 있을 땐, asum에 더함
        else if(B > A) go(bsum, time); // b가 이기고 있을 땐, bsum에 더함

		team == 1 ? A++ : B++; // a, b의 스코어 카운트
        prev = time; // 직전시간 저장
    } 
    // 아래 두 줄이 중요 !
    // 이긴 시간이 하나 나왔을 때 끝점 처리 !!
    if(A > B)go(asum, "48:00");
    else if(B > A)go(bsum, "48:00"); 
    cout << print(asum) << "\n"; 
    cout << print(bsum) << "\n";
}