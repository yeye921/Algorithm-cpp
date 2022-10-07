// "map에 요소가 있는지 없는지"를 확인하고 map에 데이터를 할당하는 부분의 로직을 다음과 같이 구축
// 단, map의 val에 0이 들어갈 때 사용하는 코드

#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
map<string, string> mp2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    if(mp.find(1) == mp.end()){   // mp[1]의 요소가 없다면
        mp[1] = 0;
    }
    
    for(auto i : mp) cout << i.first << " : " << i.second << "\n";
    return 0;
}