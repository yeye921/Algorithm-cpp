// 크기가 n인 수열
// 수열의 각 원소에 대해 오큰수를 구하려고 함 (오큰수: 오른쪽에 있으면서 해당 원소보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다)
// 그러한 수가 없는 경우에 오큰수는 -1이다

// a = [3, 5, 2, 7] => [2, 3, 5, 7]
// a = [9, 5, 4, 8]
// 1 <= 수열의 크기 <= 백만
// 1 <= 수열 원소의 개수 <= 백만

// 이 문제의 시간복잡도 => 완전탐색으로 풀면 100만^2 => 시간 초과남
// 시간초과나는 풀이법 
#include <bits/stdc++.h>
using namespace std;
int n, num;
vector<int> v;
vector<int> ret;
bool flag;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }

    // 수열의 원소들 하나씩 탐색
    for(int i = 0; i < n; i++){
        flag = true;
        int node = v[i];
        // 벡터에서 이것보다 큰 수 찾기
        // 그런데 시간복잡도를 생각해야함 => 최악의 경우: 100만 * 100만 = 0이 12개 = 헐랭..? 100억..?
        for(int j = i + 1; j < n; j++){
            if(node < v[j]){
                flag = false;
                ret.push_back(v[j]);
                break;
            }
        }
        if(flag) ret.push_back(-1);
    }
    for(int i : ret) cout << i << " ";
    return 0;
}