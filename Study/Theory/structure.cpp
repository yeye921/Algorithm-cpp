// pair를 담은 벡터: vector<pair<int, int>> v = {{1, 2}, {2, 3}, ...}
// pair 배열: pair<int, int> pi[10] = {{1, 2}, {3, 4}, ...}

// 2차원 벡터 초기화: fill(v.begin(), v.end(), vector<int>(열 크기, 채울 값)); (이전에 행 크기 선언하지 않으면 오류남)
// 2차원 배열 초기화: fill(&v[0][0], &v[0][0] + m * n, 0) 또는 memset(v, 0, sizeof(v))

// 1차원 벡터 초기화: vector<int> v(5, 0); // 크기가 5인 벡터의 원소를 모두 0으로 초기화
// 2차원 벡터 초기화: vector<vector<int>> v(5, vector<int> (4, 0)) // 5*4 벡터를 모두 0으로 초기화

// 1차원 pair 초기화: pair<int, string> pi(1, "abc"); 

// pair 배열 초기화 하는 법
#include <bits/stdc++.h>
using namespace std;
pair<int, int> pi[5];
int main(){
    for(int i = 0; i < 5; i++){
        pi[i].first = -1;
        pi[i].second = 5;
    }
    for(int i = 0; i < 5; i++){
        cout << pi[i].first << " " << pi[i].second << "\n";
    }
}

// 2차원 벡터 초기화하는 법
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v(5); // 행크기만 선언
int main(){
    // vector<vector<int>> vec(5, vector<int>(5, 1));
    // for(vector<int> vv : vec){
    //     for(int i : vv) cout << i << " ";
    //     cout << "\n";
    // }

    // fill(vec.begin(), vec.end(), vector<int>(5, -1));
    // for(vector<int> vv : vec){
    //     for(int i : vv) cout << i << " ";
    //     cout << "\n";
    // }

    fill(v.begin(), v.end(), vector<int>(4, 1)); // 2차원 벡터 초기화
    for(vector<int> vv : v){
        for(int i : vv) cout << i << " ";
        cout << "\n";
    }
}