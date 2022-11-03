// pair기반으로 만들어진 vector는 default로 first, second 순으로 차례차례 오름차순 정렬된다
#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int main(){
    for(int i = 10; i >= 1; i--){
        v.push_back({i, 10 - i});   // v = {{10, 0}, {9, 1}, ..., {0, 10}}
    }
    sort(v.begin(), v.end());
    for(auto it : v) cout << it.first << " : " << it.second << "\n";  // for(vector<int, int> it : v)로 대체 가능
    
    return 0;
}