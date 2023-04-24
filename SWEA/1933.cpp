// 정수 n의 약수를 오름차순으로 출력하는 프로그램
// 약수를 구하는 법
// m1) 1부터 n까지 증가시키면서 해당 수로 나눴을 때 나머지가 0이면 약수로 판단 > 벡터에 저장
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            v.push_back(i);
        }
    }
    for(int num: v) cout << num << " ";
    return 0;
}