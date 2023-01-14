// 무조건 한자리수부터 만들어나가면 시간초과남

// n과 같은 자리수만 탐색 => 시간초과는 안나겠지만 안되는 경우 존재
// n < n의 자릿수를 x로만 채운 것 & x가 0이 아닐때 => 같은 자리수 -1부터 탐색해야됨

// n을 스캔해나가며 만드는 방식
// 저장할 방법이 없다는게 오히려 힌트 !
#include<bits/stdc++.h>
using namespace std;
string n, ret;
string x, y;
string num, result;
// vector<int> v;
bool chk(string a, string b){ // a가 b보다 크면 1반환
    if(a.size() == b.size()) return a > b;
    return a.size() > b.size();
}
void recursive(int idx, int size){
    if(idx == size){
        // 0 < result <= n인지(n이하의 양수) && x또는 y를 포함하는지 확인
        if(result.find(x) != string::npos || result.find(y) != string::npos){
            if(chk(result, "0") && !chk(result, n)){
                //cout << result << "\n";
                if(chk(result, ret)) ret = result; // result가 ret보다 큰 수이면 최대값 갱신
            }
        }
        return;
    }
    for(int i = 0; i < 2; i++){
        result += num[i];
        recursive(idx + 1, size);
        result.pop_back(); // 시간초과나면 바꿔보기 !
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
	for(test_case = 1; test_case <= T; ++test_case) // 초기화 중요 !!
	{
        ret = "";
        cin >> n >> x >> y;
        num = x + y;

        int size = n.size();

        // m1) size - 1 부터 돌리고 안나오면 그 다음 진행
        // m2) size부터 돌리고 안나오면 size - 1 진행 => 이걸 택!
        // 한 recursive만 돌아도 시간초과 남 => 왜??
        recursive(0, size);
        if(ret == "" && size - 1 >= 1) recursive(0, size - 1);

        while(ret[0] == '0'){ // 맨 앞에 0이 붙으면 없을때까지 삭제
            ret.erase(ret.begin());
        }

        // 선물할 수 있는 수가 없으면(= ret이 업데이트 되지 않음) -1 출력
        if(ret == "") cout << "#" << test_case << " " << "-1\n";
        else cout << "#" << test_case << " " << ret << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}