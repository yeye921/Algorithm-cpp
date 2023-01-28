// 내 풀이 (맞음)
// 최대 10자리 숫자 대소비교
// m1) long long 이용 > 틀렸다고 나옴
// m2) 문자열 이용 > 이걸로 선택

// 순열구현하는 방법
// m1) next_permutation > 2개뽑을때 너무 비효율적
// m2) combi 재귀함수 이용 > 이 방법 사용

// 최대값, 최소값 찾는 법
// m1) max, min값 설정해놓고 갱신하는 형태 > 이걸로 함
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string _min = "9876543210";
string _max = "0";
vector<char> ch;
int k, num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool compare(string a, string b){ // 문자열로 숫자 대소비교하는 함수
    if(a.length() == b.length()) return a > b; // 왼쪽 끝에서부터 아스키코드 비교
    return a.length() > b.length();
}
bool check(int a, int b, char ch){ // 각 자리 숫자 비교는 int로 해도 ok!
    if(ch == '<') return a < b;
    else if(ch == '>') return a > b;
}

// 순서에 상관있게 n개 중에 r개를 뽑는 방법
void makePermutation(int n, int r, int depth){
    if(r == depth){ // 여기서 하나씩 나옴
        int j = 0;
        bool flag = 1;
        for(int i = 0; i < r - 1; i++){ // k+1자리 숫자 모두 부등호 만족하는지 체크
            if(!check(num[i], num[i + 1], ch[j])){
                flag = 0;
                break;
            }
            j++;
        }
        if(flag == 1){ 
            string s = "";
            for(int i = 0; i < r; i++){
                s += to_string(num[i]);
            }
            // cout << "부등호 만족하는 수 " << s << "\n"; // for 디버깅
            if(compare(_min, s)) _min = s; 
            if(compare(s, _max)) _max = s;
        }
        return;
    }
    for(int i = depth; i < n; i++){
        swap(num[i], num[depth]);
        makePermutation(n, r, depth + 1);
        swap(num[i], num[depth]);
    }
    return;
}
int main(){
    cin >> k;
    char c = ' ';
    for(int i = 0; i < k; i++){
        cin >> c;
        ch.push_back(c);
    }
    
    makePermutation(10, k + 1, 0);
    cout << _max << "\n";
    cout << _min << "\n";
    return 0;
}