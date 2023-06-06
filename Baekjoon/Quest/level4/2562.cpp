// 최댓값을 구하고, 최댓값의 인덱스를 구하는게 목표
// m1) max_element() 이용
// m2) 그냥 배열 탐색하면서 최댓값 갱신
// 인덱스도 구해야하는 문제니까 sort방식은 못씀

// m1)
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    for(int i = 0; i < 9; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    int idx = max_element(v.begin(), v.end()) - v.begin();
    cout << v[idx] << "\n" << idx+1 << "\n"; // 문제에서 인덱스는 0이 아니라 1부터 시작함
}

// m2)
#include <bits/stdc++.h>
using namespace std;
int mx = 0, idx = -1; // 최댓값은 최솟값부터 갱신함
int main(){
    for(int i = 0; i < 9; i++){
        int num;
        cin >> num;
        if(num > mx){
            mx = num;
            idx = i;
        }
    }
    cout << mx << "\n";
    cout << idx+1 << "\n"; // 중요!) 문제에서 인덱스는 0이 아니라 1부터 시작함
}