// 현석이의 생일 문제
// 각 자릿수 구하는 방법: ex. 일의 자리, 십의 자리, ..
// 몇자리 숫자인지 구하는 법 => m1) string으로 변환해서 size함수 이용, m2) 10으로 나누는 거 반복하면서 카운트
// 반례 n=422223324, x = 4, y = 5 => -1

// m2) 경우의 수 이용
#include<bits/stdc++.h>
using namespace std;
int n, x, y, ret;
vector<int> v;
string s;
int result[100004]; // result를 문자열로 바꿔서도 해보기 !!
void recursive(int idx, int size){
    // 여기서 더 시간 줄일 수 있는 방법..?
    // while문으로 n보다 작을때까지만 반복..?
    if(idx >= size){
        s = "";
        for(int i = 0; i < size; i++){
            // cout << result[i];
            s += to_string(result[i]);
        }
        int lim = stoi(s);
        if(lim <= n && s.find(to_string(x)) != string::npos && s.find(to_string(y)) != string::npos){ // !! x,y를 하나라도 가져야함
            // cout << s << "\n";
            ret = max(ret, lim);
        }
        return;
    }
    for(int i = 0; i < 2; i++){
        result[idx] = v[i];
        // result.push_back()
        recursive(idx + 1, size);
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
    // 선물할 수 있는 수 중에서 가장 큰 수를 출력한다
	for(test_case = 1; test_case <= T; ++test_case) // 초기화 중요!!
	{
        v.clear();
        ret = -1; // 정답

        cin >> n >> x >> y;
        v.push_back(x);
        v.push_back(y);

        // if(n < 10 * x + y){ // 만약 선물할 수 있는 수가 없으면
        //     cout << "#" << test_case << " " << "-1\n";
        //     continue;
        // }

        int size = to_string(n).size(); // n이 몇자리 수인지 알아냄
        recursive(0, size);
        cout << "#" << test_case << " " << ret << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}