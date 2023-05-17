// N개의 자연수가 주어졌을때, 최소 1개 이상의 수를 선택하여, 부분 수열의 합이 k가 되는 경우의 수를 출력해야함
// 부분수열: 어떠한 수열이 주어질 때, 그 수열에서 일부 원소를 뽑아내어 새로 만든 수열

// 완전탐색의 경우: O(2^n)
// 내 풀이: 햄버거 문제(5215)와 동일하게 비트마스킹을 이용한 완전탐색으로 품
// DP로도 풀 수 있을 것 같음
#include <iostream>
#include <vector>
using namespace std;
int T;
int n, k;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        int ret = 0;
        vector<int> v;
        cin >> n >> k;

        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }
        // 입출력 예제를 보니 인덱스를 기반으로 뽑는다고 가정해야 맞을듯 (조합)

        // m1) 완전탐색
        for(int i = 1; i < (1 << n); i++){ // 최소 1개를 뽑음 (i는 1부터)
            int sum = 0;
            bool flag = 1;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    sum += v[j];
                    if(sum > k){ // 시간초과나서 백트래킹 추가해서 막음
                        flag = 0;
                        break;
                    }
                }
            }
            if(sum == k && flag) ret++;
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}