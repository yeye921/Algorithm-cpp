// m1) a~z를 0~26에 포함여부를 배열에 저장해놓기
#include <bits/stdc++.h>
using namespace std;
int arr[30];
string str;
int main(){
    cin >> str;
    fill(arr, arr + 30, -1);
    for(int i = 0; i < str.size(); i++){
        int idx = str[i] - 'a'; // a~z를 0~26으로 대치시킴
        if(arr[idx] == -1){ // str에 포함된 알파벳이면
            arr[idx] = i; // 해당 알파벳이 처음 등장하는 위치로 초기화해줌
        }
    }
    for(int i = 0; i < 26; i++) cout << arr[i] << " ";
    cout << "\n";
}

// m2) s.find(n) 함수 이용 (문자열 s에서 문자열 n이 최초로 등장하는 인덱스 번호를 반환해준다)
// 만약 찾는 문자열이 없을 경우 string::npos를 반환한다 (npos의 값은 -1이지만 자료형이 unsigned이므로 int로 캐스팅 후 출력한다)
#include <iostream>
#include <string>
using namespace std;
int main(){
    int cnt[26] = {0,};
    string s;
    cin >> s;

    for(char ch = 'a'; ch <= 'z'; ch++){
        cout << s.find(ch) << " ";
    }
    cout << "\n";
}