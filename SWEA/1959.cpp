// 서로 마주보는 숫자들을 곱한 뒤, 모두 더할 때 최대값 구하기
// 혼자 여러 예시 만들어가면서 방법 생각해내야함 
// 입력을 주다가 안줄 때 끝내는 법: while(cin >> n)
#include <iostream>
#include <vector>
using namespace std;
int T, test_case, n, m, num;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){ 
        // 테케문 안에서 벡터 사용하면 무조건 여기다가 선언해야함 !! (안그러면 누적됨)
        vector<int> a, b;
        int ret = 0;
        cin >> n >> m;

        // 숫자열 A, B를 입력받음
        for(int i = 0; i < n; i++){
            cin >> num;
            a.push_back(num);
        }
        for(int i = 0; i < m; i++){
            cin >> num;
            b.push_back(num);
        }

        int size_a = a.size();
        int size_b = b.size();
        int mn = min(size_a, size_b);
        int mx = max(size_a, size_b);

        int num = mx - mn + 1;
        for(int i = 0; i < num; i++){ // 이것도 테스트케이스 느낌
            int sum = 0;
            int idx = 0; // 작은 사이즈의 배열은 계속 그냥 0~자기사이즈로 하면 됨
            
            // 더 큰사이즈 배열은 i번째부터 mn개까지 
            for(int j = i; j < i + mn; j++){
                // 두 숫자열을 각 순서대로 곱함
                if(size_a > size_b){
                    sum += (a[j] * b[idx]); 
                } else {
                    sum += (a[idx] * b[j]);
                }
                idx++;
            }
            ret = max(ret, sum);
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}