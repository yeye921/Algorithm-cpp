// map: 정렬이 됨, 레드블랙트리 기반, 탐색.삽입.삭제에 O(log N) 걸림
// unordered map: 정렬이 안됨, 해시테이블 구조, 탐색.삽입.삭제에 평균적으로 O(1), 최악의 경우 O(N) 걸림
// unordered_map은 최악의 경우 시간초과가 나기 때문에, 되도록이면 map을 쓰는 것이 좋음!
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> umap;
int main(){
    umap["bcd"] = 1;
    umap["aaa"] = 1;
    umap["aba"] = 1;

    for(auto it : umap){
        cout << it.first << " : " << it.second << "\n";
    }
}