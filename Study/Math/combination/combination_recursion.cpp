// 조합: 순서에 상관없이 n개 중 r개를 뽑는 것
// 조합을 재귀로 구현하는 방법 (r이 3이상일때 추천!)
#include <bits/stdc++.h>
using namespace std;
int n = 5, r = 3, a[5] = {1, 2, 3, 4, 5};
void print(vector<int> b){
    for(int i : b) cout << i << " ";
    cout << "\n";
}
// 인덱스를 기반으로 뽑음 (중복되는 요소가 있을 경우 헷갈릴 수 있기 때문)
void combi(int start, vector<int> b){
    if(b.size() == r){ // 재귀의 필수조건: 기저사례(종료조건)
        print(b);
        return;
    }
    for(int i = start + 1; i < n; i++){ // i가 왜 n까지임? > 인덱스가 n까지니까?
        b.push_back(i);
        combi(i, b);   // ⭐️ 결국 이 함수의 로직은 i를 넣고 뻬는 것임
        b.pop_back();  // 원복의 과정
    }
    return;
}
int main(){
    vector<int> b;
    combi(-1, b);
    return 0;
}