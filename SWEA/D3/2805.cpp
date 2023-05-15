// 내 풀이
// 농장의 크기 N과 농작물의 가치가 주어질 때, 규칙에 따라 얻을 수 있는 수익 구하기
#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 53
int T;
int n, num;
int arr[max_n][max_n];
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        fill(&arr[0][0], &arr[0][0] + max_n * max_n, 0);
        int ret = 0;
        cin >> n;
        
        for(int i = 0; i < n; i++){
            string s = "";
            cin >> s;
            for(int j = 0; j < n; j++){
                arr[i][j] = s[j] - '0'; // 숫자 문자를 숫자로 변환
            }
        }

        int cnt = 1; // 현재 행에서 수확할 농작물의 개수
        int start = n / 2; // 현재 행에서 수확할 농작물의 시작 인덱스

        for(int i = 0; i <= n/2; i++){ // 행 대칭 성질 이용해서 전체 행의 1/2만 탐색함
            // start에서 cnt만큼 색칠함 = 얻을 수 있는 수익 더함
            for(int x = start; x < start + cnt; x++){
                if(i == n/2){  // i가 n/2이면 한번만 수행함 (대칭인 행이 없으므로)
                    ret += arr[i][x];
                } else {
                    ret += arr[i][x];
                    ret += arr[n-i-1][x]; // 대칭인 n-i행에도 똑같이 적용시킴
                }
            }
            start--;
            cnt += 2;
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}