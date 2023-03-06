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

    // 벡터의 특정 값 삭제 (by 인덱스, 값)
    v.erase(v.begin() + i); // i번째 원소 삭제
    v.erase(remove(v.begin(), v.end(), 3), v.end());

    // 배열은 벡터와 달리 크기가 동적으로 변경되지 않기 때문에, 요소를 제거하려면 새로운 배열을 생성해야함

    // 벡터의 특정 값 추가
    v.insert(v.begin() + 1, 9); // (주소, 추가할 값)
}
vector<int> v;
int a[3] = {1, 2, 3};
int n = 5, k = 3;
void makePermutation(int n, int r, int depth){
    if(depth == r){ // 기저사례
        // 프린트
        return;
    }
    // 인덱스 기반으로 뽑음
    for(int i = depth; i < n; i++){
        swap(v[i], v[depth]);
        makePermutation(n, r, depth + 1);
        swap(v[i], v[depth]); // 순열은 조합과 달리 순서에 상관이 있기 때문에!
    }
    return;
}
void combi(int start, vector<int> b){
    if(b.size() == k){
        // 프린트
        return;
    }
    for(int i = start + 1; i < n; i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}
int main(){
    // 순열을 구현하는 방법: 1)next_permutation, 2)재귀함수
    // 1.
    sort(v.begin(), v.end());
    do{
        for(int i : v) cout << i << " ";
    } while(next_permutation(v.begin(), v.end()));

    // 2.
    int n = v.size();
    int r = 2;
    makePermutation(n, r, 0); // (전체개수, 뽑을개수, 0)

    // 조합을 구현하는 방법: 1)재귀함수, 2)중첩for문, 3)비트마스킹(0~n개 뽑는 모든 경우의수)
    // 1.
    vector<int> b;
    combi(-1, b);

    // 2. 뽑는 개수만큼 중첩시킴
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            
        }
    }
    
}