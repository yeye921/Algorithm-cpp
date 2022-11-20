// atoi(s.c_str()): 받은 문자열이 문자인지 숫자인지 판단함 (=0이면 문자열)
// 포켓몬 담는 것은 Arr이나 Map사용

// 1. String - Int
// 근데 find함수는 Arr에서 O(n)이지만 Map에서는 O(log n)이니까 Map을 사용하자!
// 따라서 string에 int를 매핑해놔야할 때는 Map을 사용해야 한다 (Arr은 시간초과)

// 2. Int - String
// Arr는 O(1)걸림 (ex. a[1]="amumu"), Map은 O(log n)걸림 
// int에 string 매핑하는 것은 Arr, Map 모두 사용 가능 (O(1)과 O(log n)는 크게 차이나지 않기 때문)

// +) map은 key,value형태인데 항상 key로 value를 찾아야함! value로 key를 찾으려고 하면 안됨
// 이렇게 1, 2처럼 두개의 자료구조를 사용해야함 (하나의 자료구조로 1,2를 하면 시간초과남)
#include <bits/stdc++.h>
using namespace std;
int n, m; // 크기: 1 ~ 10만
string s;
map<string, int> mp;
map<int, string> mp2;
int main(){
    // 이 문제의 경우 시간초과가 빡세기때문에 이것도 추가해야함
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    // 배열같은 경우는 인덱스를 기반으로 요소가 할당됨
    for(int i = 0; i < n; i++){ // 포켓몬 번호는 1부터 시작함
        cin >> s;
        mp[s] = i + 1;
        mp2[i + 1] = s;
    }
    for(int i = 0; i < m; i++){
        cin >> s;

        if(atoi(s.c_str()) == 0){ // s가 문자이면
            cout << (mp.find(s)) -> second << "\n";
        } else { // s가 숫자이면
            cout << mp2[atoi(s.c_str())] << "\n";
        }
    }
}