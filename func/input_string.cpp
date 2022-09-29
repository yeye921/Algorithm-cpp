// 문자열 따닥따닥 붙어있는 것 입력받는 법
#include <bits/stdc++.h>
using namespace std;
char a[10][10];
int main(){
    for(int i = 0; i < 2; i++){ // 2번 입력받음
		for(int j = 0; j < 4; j++){ // 길이 4를
			scanf(" %c", &a[i][j]); // 앞에 공백을 넣어주면 엔터 입력 시 무시됨 & 알아서 한글자씩 입력받음
		}
    }
    for (int i = 0; i < 2; i++){
    	for(int j = 0; j < 4; j++){
	    cout << a[i][j];
	}
	cout << "\n";
    }
    return 0;
}
/*
LLMM
MMLL
LLMM
MMLL
*/
