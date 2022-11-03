// "map에 요소가 있는지 없는지"를 확인하고 map에 데이터를 할당하는 부분의 로직을 다음과 같이 구축
#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
map<string, string> mp2;
int main(){
    // cin,cout의 속도를 높이기 위해 c와의 c++사이의 stream 동기화를 끊는다
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    if(mp[1] == 0){  // mp[1]의 요소가 없다면
        mp[1] = 2;   // mp[1]에 2를 할당함
    }
    for(auto i :mp) cout << i.first << " : " << i.second;
    return 0;
}

// But, map의 value에 0이 들어간다면 map_assign_val_0.cpp의 코드사용해야함
// 두개 다 기억하기 싫으면 그냥 이 코드 기반으로 사용하기!