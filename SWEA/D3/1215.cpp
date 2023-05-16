// 8*8 평면 글자판에서 제시된 길이를 가진 회문의 개수를 구해라
// m1) 주어진 길이만큼 자르면서 회문인지 확인하는 방식

// 행, 열에서 회문을 확인하려면 2차원 배열에 문자들을 저장하는게 좋음
#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 8
int len;
char arr[13][13];
int main(){
    for(int test_case = 1; test_case <= 10; test_case++){
        int ret = 0;
        fill(&arr[0][0], &arr[0][0] + 13*13, 0);
        cin >> len;

        for(int i = 0; i < max_n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < max_n; j++){
                arr[i][j] = s[j];
            }
        }
        
        // 해당 길이의 회문 찾기
        // 1. 행에서 회문 찾기
        for(int i = 0; i < max_n; i++){ // 행기준 탐색
            for(int j = 0; j <= max_n - len; j++){ // 주어진 길이만큼 자름
                string s = "";
                for(int k = j; k < j + len; k++){
                    s += arr[i][k];
                }
                // 회문인지 확인
                string e = s;
                reverse(s.begin(), s.end());
                if(s == e) ret++;
            }
        }

        // 2. 열에서 회문 찾기
        for(int i = 0; i < max_n; i++){ // 열기준 탐색
            for(int j = 0; j <= max_n - len; j++){
                string s = "";
                for(int k = j; k < j + len; k++){
                    s += arr[k][i];
                }
                // 회문인지 확인
                string e = s;
                reverse(s.begin(), s.end());
                if(s == e) ret++;
            }
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}