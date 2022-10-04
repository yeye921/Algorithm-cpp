#include <bits/stdc++.h>
using namespace std;
int v[10];  // 10개의 원소를 가지는 배열 v 선언
int main(){
    for(int i = 1; i <= 10; i++) v[i-1] = i;  // v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    for(int a : v) cout << a << " ";
    cout << "\n";

    auto a = find(v, v + 10, 100); // v와 v+10은 탐색할 원소의 시작과 끝을 가리키는 이터레이터이다.
    if(a == v + 10) cout << "not found" << "\n"; // find함수가 last를 리턴하면 찾지 못했다는 의미 
    
    fill(v, v + 10, 10);  // first부터 last까지 10으로 채움
    for(int a : v) cout << a << " ";
    cout << "\n";
    return 0; 
    }
