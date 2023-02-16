// 영어 대소문자 판단하는 방법: int isupper(int c), islower(int c) 맞으면 !=0 아니면 0 반환
// 문자열을 문자로 바꾸는 방법?? (이외 각종 변환하는 방법들) > 문자열에서 인덱스 기반으로 접근하면 문자임!
// set 자료구조 사용법 > set 원소들을 인덱스를 기반으로 접근하면 안됨!! 

// 50%에서 틀림 !!! > "알파벳 전체"에서 dep개 만큼 뽑아야 함 > 맞음
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
    if(cnt == dep){ // 각 경우의 수마다 읽을 수 있는 단어의 최대 개수 세야함
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
    // 내가 틀린 이유: list에 들어있는 것중에 dep개를 뽑는 것이 아니라 알파벳 전체(이미 뽑은거는 제외)에서 dep개 만큼 뽑아야 한다!!
    for(int i = start + 1; i < 26; i++){
        if(visited[i]) continue; // 이미 뽑은 알파벳은 뽑지 않음 
        visited[i] = 1;
        combi(i, cnt + 1);
        visited[i] = 0;
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
    dep = k - 5; // 뽑을 개수
    combi(-1, 0);
    cout << ret << "\n";
}