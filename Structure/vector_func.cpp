// vector와 vector 함수들 소개
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    // push_back(): 뒤에 요소 추가
    for(int i = 0; i <= 10; i++) v.push_back(i);

    // 이런 형태의 반복문은 array v에 있는 요소 값이 a에 하나씩 할당된다
    // v의 요소값 형식과 a의 형식이 동일한 것이 좋으므로 auto로 선언하는 것이 좋다
    for(int a : v) cout << a << " ";  
    cout << "\n";

    // pop_back(): 뒤에 요소 제거
    v.pop_back();
    for(int a : v) cout << a << " ";
    cout << "\n";

    // erase(지우고싶은 원소의 주소) OR erase(first, last): 벡터 v에서 원소 삭제
    // 벡터 v의 시작 주소: v.begin(), 벡터 v의 i번째 원소 주소: v.begin()+ i
    v.erase(v.begin(), v.begin() + 2); 
    for(int a : v) cout << a << " ";
    cout << "\n";

    // find(first, last, 찾고싶은 값): range에서 찾는 값이 발견되면 그 위치를, 발견되지 않으면 last를 리턴
    auto a = find(v.begin(), v.end(), 100);
    if(a == v.end()) cout << "not found" << "\n";

    // fill(first, last, val): 벡터의 first번째 부터 last번째 위치까지 val으로 채움
    fill(v.begin(), v.end(), 10);     // 벡터 v의 처음부터 끝까지를 모두 10으로 채움 ex. fill(v.begin(), v.begin()+4, 10): v의 처음부터 4번째까지 10으로 채움
    for(int a : v) cout << a << " ";  // 10 10 10 10 10 10 10 10 10
    cout << "\n";

    // clear: 배열 초기화
    v.clear();
    cout << "아무것도 없을까? \n";
    for(int a : v) cout << a << " ";
    cout << "\n";
    return 0;
}