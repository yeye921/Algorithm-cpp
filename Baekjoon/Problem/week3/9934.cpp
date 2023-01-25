// 완전 이진 트리: 마지막 레벨을 제외하고는 모든 레벨이 완전히 채워져 있음 (왼쪽에서부터 채워짐)
// double pow(double base, double n): base의 n제곱 구하는 함수
// double sqrt(double x): 루트 x를 구하는 함수

// 내 풀이: 재귀 진행
#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> num;
vector<int> tree[10]; // 2차원 배열보다 요 1차원 벡터 배열이 더 적합함
void go(int level, vector<int> node){
    vector<int> temp;
    int root_idx = node.size() / 2;
    tree[level].push_back(node[root_idx]); // 루트 노드 삽입
    
    if(root_idx == 0){ // 기저사례: node에 하나만 남으면(즉, 마지막 레벨이면) 루트에 넣고 종료
        return;
    } 
    
    // 왼쪽노드 진행
    for(int i = 0; i < root_idx; i++) temp.push_back(node[i]);
    go(level + 1, temp); 
    
    // 오른쪽 노드 진행
    temp.clear();
    for(int i = root_idx + 1; i < node.size(); i++) temp.push_back(node[i]);
    go(level + 1, temp);

    return;
}
int main(){
    cin >> k;
    int node_cnt = pow(2, k) - 1; 
    int n = 0;
    for(int i = 0; i < node_cnt; i++){ // 노드의 개수는 2^k - 1개
        cin >> n;
        num.push_back(n);
    }
    go(0, num);

    for(int i = 0; i < k; i++){
        for(int n : tree[i]) cout << n << " ";
        cout << "\n";
    }
    return 0;
}                     