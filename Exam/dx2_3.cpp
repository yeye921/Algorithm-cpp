// n이하의 양의 정수 (x, y로 이루어진 수) => 양의 정수 !!! >0 이어야 함 !!
// 선물할 수 있는 수 중에서 가장 큰 수를 출력
// 만약 선물할 수 있는 수가 없으면 -1 출력
// 완전 잘못 생각함 !! => 삼성에는 이런 문제가 많은 것 같음
// x또는 y로 이루어진수임 !! 둘 중 하나만 들어가도 됨 !!
// 문자열이름.erase(문자열이름.begin() + (제거할 위치 - 1));

// 반례 
// 9 0 9 => 9가 나와야 함
// 100 1 2 => 22이 나와야 함
// 5442 0 4 => 4444
// 89 0 9 => 9
// 6 3 7 => 3
// result를 string으로 한 버전 !!!
#include<bits/stdc++.h>
using namespace std;
string n, ret;
int x, y;
vector<int> v;
string result = "";
// 그냥 이 함수가 잘못되었음
// 12 > 21 > 121 > 122 > .. 이런식으로 만들 수 있어야 함
// string으로 큰 수 작은 수 비교하는 방법
bool chk(string a, string b){
    if(a.size() == b.size()) return a > b;
    return a.size() > b.size();
}
void recursive(int idx, int size){
    if(idx >= size){
        //cout << result << "\n";
        //lim > n 만 아니면 됨
        bool check = chk(result, n);
        if(check && (result.find(to_string(x)) != string::npos || result.find(to_string(y)) != string::npos)){ // 빠진조건: lim <= n
            // ret = max(ret, lim);
            if(chk(result, ret)) ret = result; // result가 ret보다 큰 수이면
        }
        return;
    }
    for(int i = 0; i < v.size(); i++){
        result += to_string(v[i]);
        recursive(idx + 1, size);
        result.pop_back();
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
        v.clear();
        ret = "0";
        cin >> n >> x >> y;
        v.push_back(x);
        v.push_back(y);

        if(n.size() == 1 && stoi(n) < x){
            cout << "#" << test_case << " " << "-1\n";
            continue;
        }

        int size = n.size();

        // 반복문 안에서 recursive 돌리면 되겠다!! => 여기서 시간초과????
        for(int i = 0; i < size; i++){ // 100 1 2에서 에러남
            result = "";
            recursive(0, i + 1);
        }
        // recursive(0, size);
        while(ret != "0" && ret[0] == '0'){ // 맨 앞이 0이면 계속 지움
            ret.erase(ret.begin());
        }
        if(ret == "0") ret = "-1";
        cout << "#" << test_case << " " << ret << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}