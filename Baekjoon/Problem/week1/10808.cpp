// counting star는(카운트를 할 때는) 맵 또는 배열을 사용 (중요!!)

// 1. map 자료구조는 key와 value형태로 이루어짐
//    a라는게 몇개 들어가는지 체크하기 위해 key = a, value = a의 개수를 저장함
// 2. array는 cnt[1]++ 이런식으로 사용 가능

// 언제 사용
// map => string을 기반으로 할 때 사용 (ex. "큰돌"이라는 string이 몇개냐)
// array => integer를 기반으로 할 때 사용 (ex. 1,2가 몇개냐)
// 반례) array에서 sparse하게 들어오는 경우 map을 사용해야함 (ex. 배열크기가 10만 이상일 경우 <= 공간복잡도 초과)

// 지금 이 문제는 "문자열을 기반으로 문자를 counting하는 것"임
// 문자는 아스키코드를 기반으로 숫자로 나타낼 수 있음 => 그래서 배열을 사용해야 됨
// c++에서는 cnt["a"] => cnt[97]로 알아서 변환됨
// 그냥 cnt[a]로 하는 것보다 (지금 문자가 a~z범위니까) 평행이동시켜서 cnt[a - ("a" or 97)]가 더 효율적임

// +)
// 아스키 코드(문자가 숫자로 매핑되있는 것)는 딱 2개만 외우면 됨
// 대문자 A는 65, 소문자 a는 97 (알파벳개수는 26개)

#include<bits/stdc++.h>
using namespace std;  
string str; 
int cnt[26]; // 영문자를 아스키코드 값으로 저장하는 배열
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str; 

    // m1) 
    // 소문자는 97부터 시작 (ex. a = 97) 
    // => 문자에 97을 뺀 인덱스에 있는 값을 1 증가시킴으로써 단어에 포함된 영문자의 개수를 배열로 나타낼 수 있다
    for(char a : str){
    	cnt[a - 'a']++;
	}

    /* m2)
    for(int i = 0; i < str.size(); i++){
        cnt[str[i] - 97] += 1;
    }
    */

	for(int i = 0; i < 26; i++) cout << cnt[i] << " ";
	 
	return 0; 
}