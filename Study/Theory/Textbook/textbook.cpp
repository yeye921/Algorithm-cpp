// 교안 내용 복습용
#include <bits/stdc++.h>
using namespace std;

// c++에서 많이 사용되는 문자열에 관한 함수
// reverse(s.begin(), s.end())
// s.substr(index, 개수)
// s.find("abc")
string dopa = "amumu is best";
int main(){
    cout << dopa << "\n";
    if(dopa.find("amumu") != string::npos){
        cout << "dopa안에 amumu 존재!\n";
    }
    cout << dopa.substr(0, 3) << "\n"; // dopa의 0번째부터 3개의 문자 자름
    reverse(dopa.begin(), dopa.end()); // 문자열 뒤집기
    cout << dopa << "\n";
}

// 문자열을 문자열을 기준으로 나누는 split 함수
// (문자열의 길이가 n일때 O(n)의 시간복잡도를 가짐)
// ex. "aaa bbb ccc"를 {"aaa", "bbb", "ccc"}로 나타내고 싶을 때 사용
vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length()); 
    }
    ret.push_back(input);
    return ret;
}
int main(){
    string s = "aaa bbb ccc";
    vector<string> v = split(s, " ");
    for(str : v) cout << str << "\n";
}

// 입력받은 글자가 문자열인지 숫자인지 확인하는 함수 => atoi(s.c_str())
// 입력받은 문자열이 문자라면 0을 반환하고 그게 아니라면 숫자를 반환함
string s = "1";
string s2 = "amumu";
cout << atoi(s.c_str()) << "\n"; // 1
cout << atoi(s2.c_str()) << "\n"; // 0

// int, 4바이트짜리 정수 => -20억 ~ 20억까지 표현가능
// int의 최대값으로 다음과 같이 설정 => INF + INF라는 연산이 일어날 수 있기 때문에 오버플로 방지하기 위해
const int INF = 987654321;
const int INF2 = 1e9;

// long long, 8바이트짜리 정수
typedef long long ll;
ll INF = 1e18;

// double 실수형 
double pi = 3.221;

// unsinged long long, 8바이트짜리 양의 정수
// -를 표현할 수 없고 그 범위를 몽땅 +범위에 추가한 것, 아주 가끔 사용

// 입력
// cin은 개행문자(띄어쓰기, 엔터)를 구분하여 입력받음
// getline은 개행문자를 포함해서 입력받음
string s = "김예원 화이팅";
getline(cin, s);
cout << s << "\n";

// 따닥따닥 붙어있는 것을 입력받는 법
// 1. string으로 변환
// 2. scanf("%1d", &a[i][j]);

// 입력이 계속해서 이어질 때
while(cin >> n)
while(scanf("%d", &n) != EOF)

// 소문자나 대문자로 된 문자를 숫자로 바꾸는 법
char a = 'a';
cout << a - 'a' << "\n";
cout << a - 97 << "\n";


// # 자료구조 - vector
// 동적으로 요소를 할당할 수 있는 동적 배열
// vector에서 자주 사용되는 함수: v.erase(), find(), fill(), clear(), pop_back(), push_back()
vector<int> v(5, 100); // 5크기의 벡터를 선언하고 100으로 채운 모습
vector<int> = {1, 2, 3}; // int형 벡터 생성 후 1, 2, 3으로 초기화
v.erase(v.begin() + i); // i번째 요소 삭제
v.erase(v.begin(), v.begin() + 1); // 범위로 삭제
auto a = find(v.begin(), v.end(), 100);
fill(v.begin(), v.end(), 10); // 벡터 초기화
v.clear(); // 벡터 초기화

// Array - 정적배열. 연속된 메모리 공간이며 스택에 할당됨. 컴파일 단계에서 크기가 결정됨
// array에서 자주 사용되는 함수: find(), fill()
int v[10];
auto a = find(v, v + 10, 100);
if(a == v + 10) cout << "not found" << "\n";
fill(v, v + 10, 10);

// 배열 초기화하는 함수: fill & memset
fill(&a[0][0], &a[0][0] + m*n, 채울 값);
memset(a, 0또는 -1, sizeof(a));

// 배열 복사하는 함수: memcpy
memcpy(temp, a, sizeof(a)); // 복사받을 배열 > 복사할 배열 순으로 들어감!

// pair: 두가지의 값을 담아야 할 때 사용
// tuple: 세가지 이상의 값을 넣을 때 사용
// tie: pair또는 tuple에 들어있는 두가지 이상의 값을 끄집어낼 때 사용
pair<int, int> pi;
tuple<int, int, int> tl;
int a, b, c;
int main(){
    pi = {1, 2};
    tl = make_tuple(1, 2, 3);
    tie(a, b) = pi;
    cout << a << b << "\n";
    tie(a, b, c) = tl;
    cout << a << b << c << "\n";
}

// array나 vector를 정렬하는 sort함수
// sort(first, last, cmp), cmp는 따로 설정하지 않으면 자동으로 오름차순 정렬된다
vector<int> a;
int b[5];

// 1. 오름차순 정렬
sort(b, b + 5);
sort(b, b + 5, less<int>());

sort(a.begin(), a.end());
sort(a.begin(), a.end(), less<int>());

// 2. 내림차순 정렬
sort(b, b + 5, greater<int>());
sort(a.begin(), a.end(), greater<int>());

// pair를 기반으로 만들어진 Vector의 경우 default로 first, second, third순으로 차례차례 오름차순 정렬된다
// pair를 기반으로 내림차순 정렬하려면? => 커스텀 연산자 만들어야함
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first; // first는 내림차순, second는 오름차순 정렬
}

// map 자료구조
// "김예원" : 1처럼 string : int 형태로 값을 할당해야 할 때 사용
// key와 value형태로 이루어져있고 레드블랙트리라는 구조를 내장하고 있음
// 데이터를 삽입할 때 "정렬된" 위치에 삽입하게 됨
// map에서 자주 사용되는 함수들: clear(), size(), erase(해당 key값을 지움)
map<string, int> mp;
int main(){
    mp.insert({"test1", 1});
    mp["test1"] = 4; // 이 방법을 권장

    for(auto element : mp){
        cout << element.first << "::" << element.second << "\n";
    }

    // map의 find메소드는 찾지 못하면 end() 이터레이터를 반환함
    auto search = mp.find("test4");
    if(search != mp.end()){ // search는 찾은 값의 위치를 가리키는 포인터
        cout << "found: " << search -> first << " " << (*search).second << "\n";
    }

    // 이런식으로 바로 int형을 증가시킬 수 있음
    mp["test1"]++;
    cout << mp["test1"] << "\n";

    cout << mp.size() << "\n";
    mp.erase("test1");
    cout << mp.size() << "\n";
} 

// map의 경우 해당 인덱스에 참조만 해도 맵에 값이 생기며 맵의 요소가 생기게 됨

// "map에 요소가 있는지 없는지"를 확인하고 맵에 데이터를 할당하는 로직
map<int, int> mp;
int main(){
    if(mp.find(1) != mp.end()){
        mp[1] = 2;
    }
    for(auto it : mp) cout << it.first << " " << it.second;
}

// set 자료구조
// 특정 순서에 따라 고유한 요소를 저장하는 컨테이너
// "중복된 요소는 없고" 오로지 희소한 값만 저장하는 자료구조
// 나머지는 map과 똑같음
int main(){
    set<pair<string, int>> st;
    st.insert({"test", 1});
    st.insert({"test", 1});
    cout << st.size() << "\n"; // 1
    
    set<int> st2;
    st2.insert(1);
    st2.insert(2);
    for(auto it : st2) cout << it << "\n"; 
}

// multiset 자료구조
// 중복되는 원소도 집어넣을 수 있는 자료구조 
// key, value형태로 집어넣을 필요가 없고 넣으면 자동적으로 정렬되는 편리한 자료구조
// erase, find, insert가 가능함
multiset<int> s;
int main(){
    s.insert(12);
    s.insert(10);
    s.insert(22);
    s.insert(2);
    s.insert(85);
    s.insert(22);

    cout << "정렬 후 출력\n";
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }

    auto it1 = s.find(10);
    auto it3 = s.find(85);

    s.erase(it1, it2); // 10부터 85이전까지 삭제                                                    
    cout << "삭제 후 출력\n";
    for(auto it = s.begin(); it != s.end(); it++){
        cout << (*it) << " ";
    }
}



// ---------------------------52~70p까지 건너뜀
// 1.5 수학
// 경우의 수라고 했을 때 기본적으로 순열과 조합이 생각나야 함

// 순열: 순서가 정해진 임의의 집합을 다른 순서로 섞는 연산
// 서로 다른 n개 중에 r개를 (순서에 상관 있이) 뽑는 경우의 수

// 순열을 코드로 구현하는 법
// 1. next_permutation(오름차순의 배열을 기반으로 순열을 만들 수 있음)과 prev_permutation(내림차순..) 이용
// 매개변수로는 순열을 만들 범위를 가리키는 [first, last)를 집어넣음
#include <bits/stdc++.h>
using namespace std;
void printV(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}
int main(){
    int a[3] = {1, 2, 3};
    vector<int> v;
    for(int i = 0; i < 3; i++) v.push_back(a[i]);
    
    // m1) next_permutation
    do{
        printV(v);
    }while(next_permutation(v.begin(), v.end()));
    
    cout << "---------------\n";
    v.clear();
    for(int i = 2; i >= 0; i--) v.push_back(a[i]);

    // m2) prev_permutation
    do{
        printV(v);
    }while(prev_permutation(v.begin(), v.end()));
}

// 2. 재귀를 이용해서 순열을 구현하는 방법 !!
#include <bits/stdc++.h>
using namespace std;
int a[3] = {1, 2, 3};
vector<int> v;
void printV(vector<int> &v){
    for(int i : v){
        cout << i << " ";
    }
    cout << "\n";
}
void makePermutation(int n, int r, int depth){
    if(r == depth){
        printV(v);
        return;
    }
    for(int i = depth; i < n; i++){
        swap(v[i], v[depth]); 
        makePermutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
    return;
}
int main(){
    for(int i = 0; i < 3; i++) v.push_back(a[i]); // v = {1, 2, 3}
    makePermutation(3, 3, 0); // n, r, depth
}// 123, 132, 213, 231, ...


// 조합: 오로지 몇명을 다양하게 뽑을 때 사용
// 서로 다른 n개중에 r개를 (순서에 상관 없이) 뽑는 경우의 수

// 조합을 구현하는 방법
// 1. 재귀함수를 이용 (뽑은 것의 "인덱스"를 출력하는 함수)
int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5}; // 5개 숫자중 3개 뽑는 경우의 수
void print(vector<int> b){
    for(int i : b) cout << i << " ";
}
void combi(int start, vector<int> b){ // b: 뽑은 것을 담을 벡터
    if(b.size() == k){
        print(b);
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
    vector<int> b;
    combi(-1, b);
    return 0;
} // 012, 013, 014, ...

// 2. 중첩 for문 이용
// 뽑는 개수(r)가 작을 때는 이렇게 구현
// ex. r = 3이면 3중 for문으로 구현
int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};
int main(){
    // m1)
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                cout << a[i] << a[j] << a[k] << "\n"; // a에서 3개를 뽑을 경우의 수
            }
        }
    }
    // m2)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                cout << a[i] << a[j] << a[k] << "\n";
            }
        }
    }
}

// 정수론
// 최대공약수 구하는 법 (a < b)
int gcd(int a, int b){
    return gcd(b % a, a);
}

// 최소공배수 구하는 법 (lcm = a*b / 최대공약수)
int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}
int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}
int main(){
    int a = 10, int b = 12;
    cout << lcm(a, b) << "\n";
}