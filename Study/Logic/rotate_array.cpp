// 배열 부분 회전하는 법
// 배열의 1번부터 4번까지만 한칸씩 앞으로 회전하는 로직을 구현하는 법
#include <bits/stdc++h.>
using namespace std;
vector<int> v;
int main(){
    for(int i = 1; i <= 6; i++) v.push_back(i);
    int i = 1;
    int temp = v[i];
    v[i] = v[i + 1];
    v[i + 1] = v[i + 2];
    v[i + 2] = v[i + 3];
    v[i + 3] = temp;
    for(int i : v) cout << i << " ";
    
    return 0;
}