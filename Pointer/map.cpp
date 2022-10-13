#include <bits/stdc++.h>
using namespace std;
int v[10];
int main(){
    unordered_map<string, int> umap;
    // 원소를 추가하는 방법 3가지
    umap.insert({"test", 1});
    umap.emplace("test5", 5);
    umap["test1"] = 4;  // 이렇게 변경, 추가도 가능. 이 방법을 권장

    for(auto element : umap){
        cout << element.first << " : " << element.second << "\n";
    }
}