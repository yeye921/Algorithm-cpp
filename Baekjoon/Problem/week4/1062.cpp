// 큰돌 풀이
// 조합이 중요한 문제이므로 비트마스킹을 이용해서 뽑을 것임
// (따라서 a=1, b=2, c=4, d=8,...로 매핑할 것임) (c,a를 배웠다 => 5, a,b를 배웠다 => 3)
// 알파벳 개수가 최대 26개까지이므로 비트 마스킹이 가능한 것이다 > 시간 복잡도가 최대 2^30
// 해당 글자를 배웠냐(1) 안배웠냐(0)로 각 알파벳에 대해 두가지 경우의 수만 가능함

// 핵심 알고리즘
// if(읽어야 하는 것 & 배운 것 == 읽어야 하는 것)이면 그 단어는 읽을 수 있는 것이다

// 모든 단어가 anta로 시작하고 tica로 끝나기 때문에 a,c,n,t,i는 무조건 배워야 한다
#include <bits/stdc++.h>
using namespace std;
int n, m, words[51];
string s; 
int count(int mask) {
    int cnt = 0;
    for (int word : words) { 
        if(word && (word & mask) == word)cnt++; // 읽을 수 있는 단어면 cnt 증가
    }
    return cnt;
}

int go(int index, int k, int mask) {
    if (k < 0) return 0;
    cout << index << " " << k << " " << mask << "\n";
    if (index == 26) return count(mask); // 기저사례: 끝까지 왔으면(=모든 알파벳에 대해 배웠냐/안배웠냐를 결정함) > 읽을 수 있는 글자를 세야 함
    int ret = go(index+1, k-1, mask | (1 << index));  // 배웠으면 k-1
    if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a') { // a,c,n,t,i는 무조건 배워야하는 단어 !
        ret = max(ret, go(index+1, k, mask)); // a,c,n,t,i가 아니면 안배워도 됨
    }
    return ret;
}
int main() { 
    cin >> n >> m; 
    for (int i=0; i<n; i++) { 
        cin >> s;
        for (char str : s) {
            words[i] |= (1 << (str - 'a')); // 알파벳을 이진수로 변환해서 word라는 배열에 담음
        }
    }
    cout << go(0, m, 0) << '\n'; // 재귀함수 호출
    return 0;
}
/* 이해하기 힘들면 이 예제 한번 출력해 보기
2 3
antaxxxxxxxtica
antarctica
*/