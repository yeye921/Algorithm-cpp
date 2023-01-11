// 어떻게 이런 생각을 하지?? 내 풀이와 비교해보기 !!

// 이 문제의 중요한 점 2가지
// 1. 누적합과 인덱스를 기반으로 방향성을 정해놓고 탐색해야한다
// 2. 숫자와 기호를 나눠서 해야된다 (3+8*5 => 385, +*)

// 완전탐색을 할 때는 index를 기반으로 할 생각을 해야함!! (DAG: 방향성이 있고 사이클이 없는 그래프를 기반)
// 완전탐색 문제는 이렇게 경우의 수가 정해져 있음

// 주절주절
// 방향성을 해놓으니까 누적합을 기반으로 할 수 있는것 => ..? 누적합을 계속 넘기는 것
// 지금 이 인덱스까지 들어온 누적합을 기반으로 해서 두가지 경우의 수 밖에 없다
// 이 인덱스를 기반으로 했을때는 어떤 경우의 수가 있는가.
#include <bits/stdc++.h>
using namespace std;  
vector<int> num; 
vector<char> oper_str; 
int n, ret = -987654321; // 최대값은 항상 최소값부터 !
string s; 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);   
} 
// 숫자 2개와 연산자가 주어졌을 때 계산
int oper(char a, int b, int c){
    if(a == '+') return b + c; 
    if(a == '-') return b - c; 
    if(a == '*') return b * c;  
} 

void go(int idx, int _num){
    cout << idx << " : " << _num << "\n"; // for 디버깅
    // 재귀의 필수조건: 기저사례 (항상 완전탐색은 기저사례 먼저 세워라)
    if(idx == num.size() - 1){ // 끝까지 왔으면 종료 (num.size말고 oper.size로 해도됨)
        ret = max(ret, _num); // ret에 max값 갱신해나감
        return;
    }
    // 핵심: 두가지 경우의 수 밖에 없다
    // ex. 3*8+5는 1)24+5와 2)3*13밖에 없다 => 이걸 인덱스로 구현해보면 됨
    go(idx + 1, oper(oper_str[idx], _num, num[idx + 1])); // 1)
    if(idx + 2 <= num.size() - 1){ // go에 idx+2를 넘기니까 항상 오버플로 체크해야함 
        int temp = oper(oper_str[idx + 1], num[idx + 1], num[idx + 2]); 
        go(idx + 2, oper(oper_str[idx], _num, temp));     // 2)
    } 
    return;
} 
int main(){
    fastIO();
    cin >> n;  
    cin >> s; 
    // 숫자와 기호를 나눠서 저장
    for(int i = 0; i < n; i++){
        if(i % 2 == 0)num.push_back(s[i] - '0'); // 문자를 숫자로 변환
        else oper_str.push_back(s[i]);
    } 
    go(0, num[0]); // 초기값을 기반으로 탐색시작
    cout << ret << "\n";
    return 0;
} 