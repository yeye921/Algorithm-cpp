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

    // map의 find메소드는 찾지 못하면 end() 이터레이터 반환함 (iterator == pointer)
    // 1. 화살표 함수(->)를 통해 객체의 요소에 접근할 수 있음 ex.(pointer_name)->(variable_name)
    // 2. 포인터가 주소값이니 *를 통해 값을 반환할 수도 있음 ex. *(pointer_name)
    auto search = umap.find("test1");
    if(search != umap.end()){
        cout << "found :" << search -> first << " " << (*search).second << "\n";
    } else {
        cout << "not found.." << "\n";
    }
    // 이런식으로 바로 int형을 증가시킬 수 있음
    umap["test1"]++;
    cout << umap["test1"] << "\n";

    cout << umap.size() << "\n";
    umap.erase("test1");
    cout << umap.size() << "\n";

    return 0;
}