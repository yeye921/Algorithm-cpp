// map은 string : int 형태로 값을 할당해야할 때 사용
// key와 value형태로 이루어져있음, 데이터를 삽입할 때 "정렬된"위치에 삽입하게 됨
// 정렬을 보장하지 않는 unordered_map과 정렬을 보장하는 map 두가지가 있음

#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main(){
    // map에 원소를 넣는 방법
    mp.insert({"test1", 1});
    mp.emplace("test5", 5);
    mp["test1"] = 4; // 권장하는 방식! 이렇게 추가하거나 변경도 가능

    // map 출력
    for(auto element : mp){
        cout << element.first << " :: " << element.second << '\n'; 
    }

    // map의 find메소드는 찾지 못하면 end() 이터레이터를 반환함
    auto search = mp.find("test4");
    if(search != mp.end()){
        cout << "found :" << search -> first << " " << (*search).second << "\n";  // 여기가 포인트!!
    } else {
        cout << "not found..." << "\n";
    }

    // 이런식으로 바로 int형을 증가시킬 수 있음
    mp["test1"]++;
    cout << mp["test1"] << "\n";

    cout << mp.size() << "\n";  // 2
    mp.erase("test1");
    cout << mp.size() << "\n";  // 1

    return 0;
}
