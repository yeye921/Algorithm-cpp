// Q. 영어 대소문자 판단하는 방법
// 문자열을 문자로 바꾸는 방법?? (이외 각종 변환하는 방법들) > 문자열에서 인덱스 기반으로 접근하면 문자임!
// combi 함수 사용법 !!
// set 자료구조 사용법 > set 원소들을 인덱스를 기반으로 접근하면 안됨!! 
// 벡터의 중복원소 제거하는 법

// 다음과 같은 예제가 있다고 할 때, f,s보다 h가 더 우선되어야 하는 것을 어떻게 코드로 구현?
// 3 7(a,c,n,t,i를 제외하면 2개 뽑기 가능)
// anta rfs tica => {r, f, s}
// anta h tica => {h}
// anta r tica => {r}
// r, h를 뽑아야 읽을 수 있는 단어의 개수가 최대가 됨


// 50%에서 틀림 !!! > combi 기저사례를 (cnt==dep)에서 (cnt<=dep)으로 바꾸니까 맞음
// 다 배우기 이전에도 단어의 갯수를 구해야함 !!!
#include <bits/stdc++.h>
using namespace std;
#define list aaa
int n, k, ret, dep;
bool visited[28];
string str[53]; // 벡터로 놓아도 됨
vector<int> list;
// 모든 경우의 수에서 읽을 수 있는 단어가 최대가 되는 값을 갱신시켜야 함!!
// m1) 벡터를 인자로 놓고 거기에 푸시하면서 기저사례 체크하는 방식 > visited체크 또 해줘야함 > 비효율적
// m2) dep이나 cnt를 두번째 인자로 놓고 그걸로 종료시킨 다음에 체크하는 방식 > 이걸로 함
void combi(int start, int cnt){
    if(cnt <= dep){ // 각 경우의 수마다 읽을 수 있는 단어의 최대 개수 세야함
        int sol = 0;
        for(int i = 0; i < n; i++){
            bool flag = 0;
            for(int j = 0; j < str[i].size(); j++){
                if(!visited[str[i][j] - 'a']){ // 읽을 수 없는 단어이면
                    flag = 1;
                    break;
                }
            }
            if(!flag) sol++;
        }
        ret = max(ret, sol);
    }
    for(int i = start + 1; i < list.size(); i++){
        visited[list[i]] = 1;
        combi(i, cnt + 1);
        visited[list[i]] = 0;
    }
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    // 5개 미만이면 무조건 0 반환 함
    if(k < 5){
        cout << 0 << "\n";
        return 0;
    }
    // a,c,n,t,i 방문처리
    visited['a' - 'a'] = visited['c' - 'a'] = visited['n' - 'a'] = 1;
    visited['t' - 'a'] = visited['i' - 'a'] = 1;

    // a,c,n,t,i에 속하지 않는 알파벳들을 따로 담음
    for(int i = 0; i < n; i++){
        for(int j = 0; j < str[i].size(); j++){
            if(visited[str[i][j] - 'a']) continue; // 이미 포함된 알파벳이면 건너뜀
            else list.push_back(str[i][j] - 'a');
        }
    }

    // 벡터의 중복 원소 제거 (먼저 오름차순으로 정렬 > unique함수의 리턴값부터 벡터의end까지 제거해준다)
    sort(list.begin(), list.end());
    list.erase(unique(list.begin(), list.end()), list.end());    

    // k - 5개를 뽑아야 함 > combi 함수 이용
    // k - 5개를 뽑는 것이 아니라 최대 k-5개를 뽑는 것임 !! > 왜???!!!
    dep = k - 5; // 뽑을 개수
    combi(-1, 0);
    cout << ret << "\n";
}