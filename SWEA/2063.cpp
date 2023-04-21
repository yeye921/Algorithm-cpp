// 입력으로 N개의 점수가 주어졌을 때, 중간값을 출력하기 (N은 항상 홀수)
// ex. N=5일때, 1,2,3,4,5 중간값의 인덱스는 2(즉, N-1/2)
// 풀이: 수들을 벡터에 입력받고 > 정렬한 뒤 > (N-1/2)번째 값을 출력하면 됨

// 주의할 점: 중복되는 값들이 존재하므로 중간값이 정확하려면 중복값 제거 후 인덱스로 접근해야함!
// unique()를 통해 중복값 제거하려면 sort > erase > unique 순으로 적용해야함
// +) 문제에서 테스트케이스 개수 주어지지 않을 경우, 답안에서 관련 코드 다 지워야함!!
#include <iostream>
#include <vector> 
#include <algorithm> // sort 함수
using namespace std;
int n, score, idx;
vector<int> v;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> score;
        v.push_back(score);
    }
    sort(v.begin(), v.end());
    idx = n / 2;
    cout << v[idx] << "\n";
    return 0;
}