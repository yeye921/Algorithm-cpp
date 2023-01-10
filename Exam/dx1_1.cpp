// PASS한 풀이 ! : string에 알파벳들을 담고 find함
// 원래 30/32에서 시간초과 났던 풀이: 벡터에 알파벳들을 담고 find함
#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, ret;
char a[24][24];
string s;
void dfs(int y, int x){
    bool flag = 0; // 어느 방향으로도 이동하지 못하면
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if(s.find(a[ny][nx]) != string::npos) continue; // 갖고 있는 기념품과 중복될 경우 건너뜀
        flag = 1;
        s += a[ny][nx];
        dfs(ny, nx);
        s.pop_back();
    }
    if(!flag){
        ret = max(ret, (int)s.length());
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case) // testcase => 초기화 중요!!
	{
        ret = 0;
        s = "";
        fill(&a[0][0], &a[0][0] + 24 * 24, 0);
        
        cin >> r >> c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> a[i][j];
            }
        }

        // 시작점 처리
        s += a[0][0];
        dfs(0, 0);
        cout << "#" << test_case << " " << ret << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}