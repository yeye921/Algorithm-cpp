// 문자열 내 문자열 찾는 법: input.find("abc"); (이거 절대 아님 input.find(input.begin(), input.end(), 찾는값))

// split 관련 진짜 실수 많이하는 것 !!
// ex. upload 142300 7 1  이런 식으로 입력이 들어올 때 split함수 쓸 필요가 없음
// 이미 개행문자가 포함되어 있기 때문에 그냥 cin >> s1 >> s2 >> s3로 받으면 됨
// split함수는 "aaa bbb ccc"를 진짜로 [aaa, bbb, ccc]로 표현해야 할 때 사용

// getline을 여러번 써야 하는 상황 > 특정 문자열을 기반으로 버퍼플래시를 하고 받으면 된다
// string bufferflush;
// getline(cin, bufferflush);

// 문제를 보면서 알고리즘을 먼저 생각한 후 코드를 짜야함!!

// pair 배열을 만들수도 있다 (ex. pair<int, int> pi[50];)
// 벡터 할당안된상태에서 인덱스기반으로 접근하면 오류남!!

// 1번 문제
// require 나올 때마다 정답 출력해줘야 함
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sec;
string s;
int n, m, d, idx, ver;
vector<ll> upload; // 인덱스로 접근할 때 주의하기 (string 말고 long long으로 해도 될까? > 됨!) 
pair<ll, int> client[103]; // 클라이언트의 인원 수는 최대 100명
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> s;
        if(s == "upload"){
            cin >> sec >> d >> ver;
            upload.push_back(d);
        }
        else{ // require 나오면 출력해야함
            cin >> sec >> idx;
            if(client[idx - 1].second == 0){ // 클라이언트에 로컬 파일이 없으면 (왜냐면 버전은 1부터 시작하니까!)
                client[idx - 1] = {sec, 1}; // 벡터를 이렇게 인덱스를 기반으로 할당해도 되나? > 됨!
                cout << 1 << " " << 1 << "\n";
            } else{
                int due = sec - client[idx - 1].first;
                int ver = client[idx - 1].second;
                if(due > upload[ver - 1]){ // 클라가 다운받은 시점으로부터 d초가 지났음으로 새로 받음 (가장 최신 버전 파일)
                    client[idx - 1] = {sec, upload.size()}; 
                    cout << 1 << " " << upload.size() << "\n";
                }
                else cout << 0 << " " << ver << "\n";
            }
        }
    }
    return 0;
}


