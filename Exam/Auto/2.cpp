// 암호화 문제 (암호화 = 모든 알파벳이 일정 칸만큼 밀림)
// 문서 원본 제목이 주어질 때, 주어진 문서들 중 암호화 된 제목을 찾는 문제
#include <bits/stdc++.h>
using namespace std;
#define new aaa
int n;
string s, og;
vector<string> v; 
int main(){
    cin >> n >> og; // 문서 개수, 원본 제목을 입력받음
    for(int i = 0; i < n; i++){
        cin >> s;
        v.push_back(s);
    }

    // 원본제목의 알파벳들을 옮긴 것(암호화한 것)이 v에 포함되었는지를 체크해서 출력하면 됨

    // 옮길 수 있는 칸 수의 범위는 정해져 있음 (0~26) 알파벳이 26개니까
    // m1) og를 문자하나씩 쪼개서 이동시킴? > 그래서 문자열을 하나 만듬
    for(int i = 0; i < 26; i++){
        string new = "";
        for(int j = 0; j < og.size(); j++){
            new += ((og[j] - 'A' + i) % 26) + 65; // 여기가 포인트!
        }
        auto it = find(v.begin(), v.end(), new); // 여기 시간복잡도 O(n)
        if(it != v.end()){
            cout << *it << "\n";
        }
    }
}
/*
5 YEWON
AAAAA BBBBB CCCCC ZFXPO DDDDD EEEEE
*/