// 비트마스킹 기반 내 풀이 (큰돌 변형) > 맞음 > 이 풀이가 최단시간임!!

// 핵심 알고리즘
// if((읽어야 할 단어 & 학습한 단어) == 읽어야 할 단어)이면 읽을 수 있는 단어이다

// 내가 이해 안갔던 부분 ex)
// 1 7 
// antabtica 
// 내 생각: b만 뽑으면 되는데 k가 왜 7이지?
// => 알파벳을 최소로 뽑았을 때 읽을 수 있는 단어의 최댓값이 아님
// => 그냥 뽑을 알파벳의 개수임 ! (a,b를 뽑던 a,c를 뽑던 알 바 아님)

// 10진수인 정수를 2진수로 출력하는 방법 > bitset이용
// bitset<비트 수>(bit)
#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, ret, bit;
string s;
int str[53];
void go(int start, int alpha, int dep){ // alpha = 학습한 단어들이 저장되어 있음
    // 기저사례 (뽑을 개수만큼 뽑았다)
    if(dep == cnt){
        // 읽을 수 있는 단어 개수의 최댓값 갱신
        int voc = 0;
        for(int i = 0; i < n; i++){
            if((str[i] & alpha) == str[i]){ // 읽을 수 있는 단어이면
                voc++;
            }
        }
        ret = max(ret, voc);
        return;
    }
    // 메인 로직(완탐 진행)
    for(int i = start + 1; i < 26; i++){ // !! i시작점을 start + 1로 해야 시간 단축됨!! (0부터 시작할 필요 없음 > 이미 start까지는 다 탐색한거니까 또 할 필요 없음)
        if(((1 << i) & alpha) == 0){ // a,c,n,t,i는 제외 (전에 뽑지 않았던 알파벳에 대해서만 진행) (실수 팁: i가 아니라 (1 << i)이다 !!)
            go(i, alpha | (1 << i), dep + 1); // 아래 세 줄 코드가 이 한 줄로 바뀜 !!
        }
        // visited[i] = 1;
        // go(i, cnt + 1);
        // visited[i] = 0;
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(char c : s){
            str[i] |= (1 << (c - 'a')); // 받은 문자열(=읽어야 할 단어)에 포함된 문자들을 str[i]에 비트를 켜서 표시함
        }
    }
    if(m < 5){
        cout << 0 << "\n";
        return 0;
    }

    // a,c,n,t,i는 이미 배웠다고 가정
    bit = (1 << ('a'-'a')) | (1 << ('c'-'a')) | (1 << ('n'-'a')) | (1 << ('t'-'a')) | (1 << ('i'-'a'));
    // cout << "bit " << bitset<26>(bit) << "\n";

    cnt = m - 5; // 학습시킬(=뽑을) 알파벳개수
    go(-1, bit, 0);
    cout << ret << "\n";
}