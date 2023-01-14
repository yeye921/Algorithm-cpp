#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
string N;
int x, y;
bool success;

int count_pos(string N) {
	return N.length();
}

void solution(vector<int> &result) {
	int len = count_pos(N);
	bool carry = false;

	for(int i = 0;i < len;i++) {
		int num = N[i] - '0';
		if(carry) {
			result.push_back(y);
		}
		else if(num >= y) {
			result.push_back(y);
			if(num > y) carry = true;
		}
		else if(num >= x) {
			if(x == 0 && result.empty()) {
				carry = true;
				continue;
			}
			result.push_back(x);
			if(num > x) carry = true;
		}
		else {
			if(!result.empty()) {
				int pos = result.size() - 1;
				for(int i = result.size() - 1;i >= 0;i--) {
					if(result[i] == x) {
						if(i == 0) result[i] = -1;
						else result[i] = y;
					}
					else {
						result[i] = x;
						break;
					}
				}
				result.push_back(y);
				carry = true;
			}
			else {
				carry = true;
			}
		}
	}
}



int main(int argc, char** argv)
{
	int test_case;
	int T;

	// freopen("sample_input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> result;
		success = true;
		cin >> N >> x >> y;
		solution(result);

		cout << "#" << test_case << " ";
		if(result.empty()) success = false;
		if(!success) {
			cout << -1;
		}
		else {
			string answer = "";
			for(int i = 0;i < result.size();i++) {
				if(result[i] == -1) continue;
				answer += to_string(result[i]);
			}
			cout << answer;
		}
		cout << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
// 어렸을 적 사칙 연산하듯 carry(올림) 예외 처리에 신경 쓰고, 최대한 패턴을 써서 실수를 안 하면 되는 문제였던 거 같습니다.
// 저도 여러 번 올 패스에 실패하다가, 모듈화를 하니 통과했습니다.
// 아래와 같이 테스트케이스를 만들어서 검수를 해봤는데, 일부 놓치는 테스트케이스가 있을 수 있습니다.
// 36

// 16 1 3

// 2 6 9

// 5 0 8

// 422223324 2 4

// 10 0 9

// 100 1 9

// 89 0 3

// 80 7 8

// 122223324 1 4

// 7000000 1 8

// 3230 2 3

// 2230 2 3

// 3230 0 3

// 2230 0 3

// 919 1 9

// 301 5 9

// 12309 1 3

// 900 1 8

// 700 6 7

// 615 6 7

// 810 1 8

// 810 0 8

// 80010 1 8

// 880 1 8

// 7701 0 7

// 2180 1 2

// 1183 1 5

// 11003 1 3

// 91390 0 9

// 433313 3 4

// 331031 0 3

// 2232221 2 3

// 505 5 9

// 800 0 8

// 3413 3 4

// 3333 0 5