// 목표: 두개의 수를 더했을 때 m이 나오는 경우의 수는?
// n개중 2개를 뽑는 경우의 수에 대해서 조사해야함
// 구하는 법: 1.combination 이용, 2. ..?

// 조합을 구현하는 방법
// 1. 이중for문 2. 재귀 3. Permutation 재귀로 해서 앞에 2개 자르기
// 일단 1번으로 해결해보기
#include <bits/stdc++.h>
using namespace std;
int n, m, num, ret;
pair<int, int> pi;
vector<int> v;
int main(){
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    */
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }

    // n개중에 2개를 뽑는 경우의 수
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            // 뽑은 2개를 더한 값이 m이 되는지 확인
            if(v[i] + v[j] == m){ // i,j가 인덱스로 이용되는 점 주의하기!
                ret += 1;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}