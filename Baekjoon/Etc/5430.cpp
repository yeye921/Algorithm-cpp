// 이 문제에서 가장 필요한 로직
// 1. 배열 string을 진짜 정수형 배열로 나타내기
// 2. RDD 이런 명령어를 수행하는 로직 만들기
// => 매번 뒤집으면 비효율적임. 

// 큰돌 방식
// 매번 뒤집지 않고 이렇게 효율적으로 명령어를 수행하는 로직
// flag로 뒤집혔는지 여부를 저장하고 flag가 0이면 pop_front(), 1이면 pop_back()을 수행한다 (큰돌생각. 놀라움)

// 내 방식과 차이
// 나는 뒤집힘 횟수를 1또는 0으로 대치하는 로직을 생각함. 큰돌은 뒤집음 여부를 변수로 저장하고 뒤집기 연산대신 pop_front(), pop_back()을 수행함

// 우리는 가장 앞부분과 뒷부분에서 연산을 많이 할거기 때문에 deque 자료구조를 사용한다
#include <bits/stdc++.h>
using namespace std;
int T, N, x;
string P, order;
int main(){ 
	cin >> T;  
    for(int t = 0; t < T; t++){ 
        deque<int> D;
        cin >> P >> N >> order;
        x = 0;
        for(char c : order){
        	if(c == '[' || c == ']') continue;
        	// 숫자가 나오면 현재 수*10 한 뒤 더함 (2, 99, ...에서 99를 9가아니라 99로 받기위한 과정)
            if(c >= '0' && c <= '9') x = x*10 + c-'0';
            // 아닐 경우 현재 수를 덱에 넣음
            else{
                if(x > 0) D.push_back(x);
                x = 0; 
            }
		} 
		if(x > 0) D.push_back(x);
        // 초기에는 에러 없음, 뒤집히지 않은 상태
        bool error = false, rev = false;
 		for(char a : P){
 			if(a == 'R') rev = !rev; 
 			else{
                // 비어있는데 제거하려 하면 에러
                if(D.empty()){
                    error = true;
                    break;
                }
                if(rev) D.pop_back(); // 뒤집힌 경우에는 뒤에서 pop
                else D.pop_front();  // 뒤집히지 않은 경우에는 앞에서 pop
			}
		}  
        // 에러가 발생한 경우
        if(error) cout << "error" << '\n';
        // 아닐 경우 덱의 원소를 하나하나 출력
        else{
        	cout << "["; 
            // 덱이 뒤집힌 상태면 진짜로 뒤집어 준다.
            if(rev) reverse(D.begin(), D.end());
            for(int i = 0; i < D.size(); i++){
        		cout << D[i];  
                if(i < D.size()-1) cout << ",";
            }
        	cout << "]\n";  
        }
    }
} 