// 기념품을 최대한 많이 구매하되, 종류가 겹치지 않도록 여행경로를 계획하고 싶다
// 1행 1열에서 시작했을 때, "같은 기념품을 두개이상 사지않도록" 여행을 떠나는 방법 중에, 가장 많은 기념품을 구매할 수 있는 최대 개수 !!
// Q. 벡터를 전역변수로 초기화해서 이용해도 똑같은 결과가 나올까..?
#include<bits/stdc++.h>
using namespace std;
#define map aaa
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, ret;
char map[23][23];
bool visited[23][23];
void dfs(int y, int x, vector<int> &v){ // 만약에 더 이동할 수 없는 경우 가짓수 비교해야함 
    cout << y << x << ":";
    for(char i : v) cout << i << " ";
    cout << "\n";
    bool flag = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if(visited[ny][nx] || find(v.begin(), v.end(), map[ny][nx]) != v.end()) continue; // 이미 방문했거나 내가 가지고 있는 기념품이면 건너뜀
        // if(find(v.begin(), v.end(), map[ny][nx]) != v.end()) continue;
        flag = 1;
        // 완탐 진행
        visited[ny][nx] = 1; 
        v.push_back(map[ny][nx]);
        dfs(ny, nx, v);
        // 완탐 해제
        visited[ny][nx] = 0;
        v.pop_back();
    }
    // 4방향 중 어떤 방향으로도 이동 못하면 최대값 비교후 종료
    if(!flag) ret = max(ret, (int)v.size());
    // cout << "ret: " << ret << "\n";
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
	for(test_case = 1; test_case <= T; ++test_case) // 초기화 중요!!
	{
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        ret = 0;
        vector<int> v;
        cin >> r >> c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> map[i][j];
            }
        }
        // 시작점 처리
        visited[0][0] = 1;
        v.push_back(map[0][0]);
        dfs(0, 0, v);
        cout << "#" << test_case << " " << ret << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
// 
// 20 20
// AACVDFHEEFDFACNCVGDFS
// SDFWRHDSDFQTGHHEDSFAS
// DFBKFASPWIFKALVKADKAW
// KAWKDCMZKFKAWLZKDFLPA
// KXVSLAWFKALCLSKLADLKC
// AKAKFKOOEKDKZKZJJDKDK
// SDVKSFPQODFKWEKFKSDKE