// 큰돌 풀이: 인덱스를 기반으로 go함수 진행, 내풀이: 노드들을 담은 벡터를 기반으로 go함수 진행
// 트리 순회 복습하기 (코테 단골문제)

// 이 문제는 트리 순회 중 inOrder(중위순회, 왼쪽 > 자신 > 오른쪽)를 이용하고 있음 !
// 숫자 리스트를 기반으로 트리를 만들어야 하는 문제
#include <bits/stdc++.h>
using namespace std; 
vector<int> ret[14];
int n, a[1030];
// 계속 왼쪽, 오른쪽, 중앙으로 나눠서 중앙을 root로 놓는 아이디어를 구현한 코드
void go(int s, int e, int level){ 
    if(s > e) return; // 범위를 나눌때 무조건 들어가는 코드 ! (스타트지점이 엔드지점보다 작거나 같다)
    if(s == e){ // 기저사례
        ret[level].push_back(a[s]); 
        return;
    }
    int mid = (s + e) / 2; // 중앙부분 끄집어냄
    ret[level].push_back(a[mid]); // 루트노드를 트리에 넣음
    go(s, mid - 1, level + 1); // 루트기준 왼쪽 노드들 재귀 돌림 (여기서 또 중앙찾고 왼쪽오른쪽나누고 재귀)
    go(mid + 1, e, level + 1); // 루트기준 오른쪽 노드들 재귀 돌림
    return;
}
int main(){
    cin >> n;
    int _end = (int)pow(2, n) - 1; // 노드의 개수 (완전 이진트리의 특징 이용)
    for(int i = 0; i < _end; i++){
        cin >> a[i]; 
    }
    go(0, _end, 1); 
    for(int i = 1; i <= n; i++){
        for(int j : ret[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
// 3
// 1, 5
// 0, 2, 4, 6