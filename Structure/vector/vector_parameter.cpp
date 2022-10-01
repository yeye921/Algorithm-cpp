// 벡터를 함수 매개변수로 넘겨서 변화시키고 싶을 때 -> call by reference로 넘겨서 수정하게함
// in c++, call by reference: 매개변수를 참조변수로 받아 인자로 전달받은 변수를 수정할 수 있게함

// 1) 벡터를 함수 매개변수로 넘길 때
#include <bits/stdc++.h>
using namespace std;
void f(vector<int> &v){
    v[0] = 100; // 벡터 v의 첫번째 원소를 100으로 초기화
}
int main(){
    vector<int> v;
    for(int i = 1; i <= 3; i++) v.push_back(i); // 즉, v = {1, 2, 3}
    f(v);                                       // v = {100, 2, 3}
    for(int i : v) cout << i << " ";
    cout << "\n";
    return 0;
}


// 2) 벡터 배열을 함수 매개변수로 넘길 때 (ex. 10개의 벡터 배열 넘기기)
#include <bits/stdc++.h>
using namespace std;
void f(vector<int> v[10]){
    v[0][0] = 1000;         // 첫번째 벡터의 첫번째 원소를 1000으로 초기화  ex. v = {{1000, ..}, ..., {...}}
}
int main(){
    vector<int> v[10];      // 10개의 벡터 선언
    v[0].push_back(100);    // 첫번째 벡터의 맨 끝에 100을 넣음 v = {{100}, ...}
    f(v);                   // v = {{1000}, ...}
    for(int i : v[0]) cout << i << " "; // 첫번째 벡터에 들어있는 것들 접근해서 출력
    return 0;
}


// 3) "2차원 벡터"을 함수 매개변수로 넘길 때
#include <bits/stdc++.h>
using namespace std;
void f(vector<vector<int>> &v){  // vector<int>형을 담는 벡터 v를 매개변수로 받음
    vector <int> vv;
    vv.push_back(10000);
    v.push_back(vv);  // 2차원 벡터 v의 맨 뒤에 벡터 vv를 삽입
}
int main(){
    vector <vector<int>> v;
    f(v);
    for(int i : v[0]) cout << i << " ";
    return 0;
}