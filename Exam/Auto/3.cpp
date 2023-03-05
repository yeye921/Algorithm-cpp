// 최대 k개의 공통지시사항을 수행하는 범위 중 최대 길이가 되는 범위를 구하는 문제
// (두 직원의 일들과 최대 k개의 공통 지시사항이 주어짐)

// 어차피 전체 지시사항들을 담을 배열과 공통지시사항을 담을 배열이 필요하기 때문에 
#include <bits/stdc++.h>
using namespace std;
int m, n, k, num, ret;
vector<int> vm, vn, total, common; // 공통 지시사항들을 common에 담아두어야 함!
int main(){
    cin >> m >> n; 
    for(int i = 0; i < m; i++){ 
        cin >> num;
        vm.push_back(num);
        total.push_back(num);
    }
    for(int i = 0; i < n; i++){
        cin >> num;
        if(find(vm.begin(), vm.end(), num) == vm.end()) total.push_back(num); // 여기서 이미 시간복잡도 n^2???
        else common.push_back(num);  
    }
    cin >> k;

    // total에서 가장 큰 값과 가장 작은 값 알아야 함
    int mn = *min_element(total.begin(), total.end());
    int mx = *max_element(total.begin(), total.end());

    // common에서 최대 k개를 뽑았을 때 일의 범위가 가장 긴 것 구하기
    // 1. 일단 k개 이하가 아니라 k개 뽑는 걸로 먼저 해보기
    int start = 0, end = 0;
    for(int i = 0; i < common.size() - k + 1; i++){
        // 3,5,7이 뽑혔을 때 우리는 맨 앞과 맨 끝 숫자만 알아내면 됨
        start = common[i];
        end = common[i + k - 1];
        // cout << common[start] << " " << common[end] << "\n";


        //  여기서 범위구하고 길이 구해야함 !!
        int s = start, e = end;
        for(int i = start - 1; i >= mn; i--){
            if(find(common.begin(), common.end(), i) == common.end()) s = i;
            else break; // 만약에 common에 포함되었으면 멈추기!
        }
        for(int i = end + 1; i <= mx; i++){
            if(find(common.begin(), common.end(), i) == common.end()) e = i;
            else break;
        }

        ret = max(ret, e - s);
    }
    cout << ret << "\n";

    // 2. k개이하 뽑는 것
    // for(int i = 1; i < k; i++){
    // }

    // 범위구하고 길이구하기 > 최대 길이 업데이트
}
/*
5 5
1 3 5 7 9
2 3 5 7 10
2
// total={1,2,3,5,7,9,10}, common={3,5,7}
5 5
3 5 7 9 10
3 5 7 9 10
3
// total={3,5,7,9,10}, common={3,5,7,9,10}
*/