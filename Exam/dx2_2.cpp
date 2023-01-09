// 완전 잘못 생각함 !! => 삼성에는 이런 문제가 많은 것 같음
// 

// 반례 
// 9 0 9 => 9가 나와야 함
// 100 1 2 => 21이 나와야 함
// 5442 0 4 => 4444가 아니라 4440이 나와야 함!!
#include<bits/stdc++.h>
using namespace std;
int n, x, y, ret;
vector<int> v;
int result[100004];
// 그냥 이 함수가 잘못되었음
// 12 > 21 > 121 > 122 > .. 이런식으로 만들 수 있어야 함
void recursive(int idx, int size){
    if(idx >= size){
        string s = "";
        for(int i = 0; i < size; i++){
            s += to_string(result[i]);   
        }
        // cout << s << "\n";
        int lim = stoi(s);
        if(lim <= n && s.find(to_string(y)) != string::npos){
            if((x == 0 && lim < 10) || s.find(to_string(x)) != string::npos){
                ret = max(ret, lim);
            } 
        }
        return;
    }
    for(int i = 0; i < v.size(); i++){
    	result[idx] = v[i];
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
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(result, 0, sizeof(result));
        v.clear();
        ret = -1;
        cin >> n >> x >> y;
        v.push_back(x);
        v.push_back(y);
        
        int size = to_string(n).size();
        // recursive(0, size);

        // 반복문 안에서 recursive 돌리면 되겠다!!
        for(int i = 0; i < size; i++){
            recursive(0, i + 1);
        }
        cout << "#" << test_case << " " << ret << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}