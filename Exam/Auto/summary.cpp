#include <bits/stdc++.h>
using namespace std;
// 각종 변환 문제
int main(){
    int n = 112;
    char ch = 'c';
    string s = "112";

    // 입력받은 문자열이 숫자인지 문자인지 확인
    atoi(s.c_str());

    stoi(s); // 문자열을 숫자로 변환
    
    to_string(n); // 숫자를 문자열로 변환

    string(1, ch); // 문자를 문자열로 변환
}

int main(){
    int i = 1;
    int arr[10] = {0, };
    vector<int> v;


    v.erase(v.begin() + i); // 벡터의 i번째 요소 삭제

    // 벡터나 배열에서 가장 큰/작은 값 구하는 법 
    int mx = *max_element(v.begin(), v.end()); // 괄호 안에 (first, last)
    int mn = *min_element(arr, arr + 10); // 최대/최소값의 주소를 반환해주기때문에 

    // min/max_element함수가 주소값을 반환해주기 때문에 바로 삭제하는 함수에 사용할 수 있어서 편하다
    v.erase(max_element(v.begin(), v.end()));

    // 배열은 벡터와 달리 크기가 동적으로 변경되지 않기 때문에, 요소를 제거하려면 새로운 배열을 생성해야함
    

    // 한번에 구하는 법
}