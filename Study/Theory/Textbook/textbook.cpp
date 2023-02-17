// 교안 내용 복습용
#include <bits/stdc++.h>
using namespace std;

// c++에서 많이 사용되는 문자열에 관한 함수
// insert(넣을위치, 넣을 문자열), erase(시작위치, 크기) (중요!!)
// reverse(s.begin(), s.end())
// s.substr(index, 개수)
// s.find("abc")
int main(){
    string a = "love is";
    a += " pain!";
    a.pop_back(); // 문자열의 가장 마지막 문자 삭제 !! (love is pain)
    cout << char(*a.begin()) << "\n"; // 문자열 a의 첫번째 문자
    cout << char(*(a.end() - 1)) << "\n"; // a의 마지막 문자

    a.insert(0, "test "); // a의 0번째 위치에 해당 문자열 삽입
    a.erase(0, 5); // 0번째 문자부터 5개 문자 삭제
}

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
    for(string str : v) cout << str << "\n";
}

// 입력받은 글자가 문자열인지 숫자인지 확인하는 함수 => atoi(s.c_str())
// 입력받은 문자열이 문자라면 0을 반환하고 그게 아니라면 숫자를 반환함
string s = "1";
string s2 = "amumu";
cout << atoi(s.c_str()) << "\n"; // 1
cout << atoi(s2.c_str()) << "\n"; // 0
// s.c_str(): 문자열을 문자로 변환하는 함수
// atoi(char c): 문자가 숫자인지 판단하는 함수


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

// Array - 정적배열. 연속된 메모리 공간이며 스택에 할당됨. 컴파일    단계에서 크기가 결정됨
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


// 역참조 연산자 (*)
// in c++, *는 곱셉 연산, 포인터 타입의 선언, 역참조로 메모리를 기반으로 변수의 값에 접근 (총 3가지가 가능)
int main(){
    string a = "abcde";
    string *b = &a; // 변수 a의 주소값을 담은 포인터 b
    cout << b << "\n";
    cout << *b << "\n"; // * 연산자를 통해 역참조를 걸어, 주소값을 기반으로 값을 참조할 수 있음
}

// 화살표 연산자(->)
// 멤버 변수가 있는 변수라면, 역참조가 아닌 화살표 연산자를 통해서도 해당 멤버 변수를 끄집어낼 수 있음
pair<int, int> a = {1, 2};
int main(){
    pair<int, int> *b = &a; // b는 a를 가리키는 포인터
    cout << b -> first << "\n"; // 화살표 연산자를 통해 해당 변수의 값을 가져옴
    cout << (*b).first << "\n";
}

// 배열 이름과 포인터
// 배열의 이름을 배열의 첫번째 주소로서 쓸 수 있다. vector는 안되고 array만 가능함
int a[3] = {1, 2, 3};
int main(){
    int *b = &a[0]; // 배열의 첫번째 주소
    int *c = a;
    cout << b << "\n";
    cout << c << "\n";
    // b와 c는 같은 값을 출력함 > 즉, &a[0]과 a는 같은 의미를 가짐

    // &a[1]을 a + 1로도 표현 가능함
    int *d = (a + 1); // 배열의 1번째 주소는 배열의 이름 + 1로 나타낼 수 있음
    cout << d << "\n";
    cout << &a[1] << "\n";
    return 0;
}

// iterator: 컨테이너에 저장되어 있는 요소의 주소를 가리키는 개체 (포인터를 일반화한 것)
// vector, map 등 각각 다르게 구현된 컨테이너들을 일반화된 이터레이터를 통해 쉽게 순회할 수 있음
// 바로는 주소값을 반환하지 못하고 &*를 통해 해당요소의 주소값 반환 가능
vector<int> v;
int main(){
    for(int i = 0; i <= 5; i++) v.push_back(i);
    for(int i = 0; i < 5; i++){
        cout << i << "번째 요소 : " << *(v.begin() + i) << "\n"; // i번째에 위치한 요소의 값 반횐
        // cout << v.begin() << "\n"; // 에러남
        cout << &*(v.begin() + i) << "\n"; // i번째 주소값 알아내려면 &*로 접근해야함 !!!
    }
    // iterator를 auto로 선언하면 아래보다 간단함
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";
    
    // 원래 iterator
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    auto it = v.begin(); // 컨테이너의 시작 위치를 반환함
    advance(it, 3); // 해당 이터레이터를 cnt까지 증가시킴 (출력: 4)
    cout << "\n";
    cout << *it << "\n";
}

// fill()과 memset(): 배열을 초기화 할 때 사용
// fill(시작값, 끝값, 초기화하는 값)
// memset(배열의 이름, 0 또는 -1, 배열의 크기) // 0, -1 이외의 값으로 초기화 불가!!
int main(){
    // 1차원 배열 초기화
    fill(v2.begin(), v2.end(), INF);
    fill(a, a + max_n, 10);

    // 2차원 배열 초기화
    fill(&a[0][0], &a[0][0] + n * m, INF);

    memset(a, -1, sizeof(a));
    memset(a2, 0, sizeof(a2));
}

// memcpy(복사받을 배열, 복사할 배열, sizeof(복사할 배열)):
// 어떤 변수의 메모리에 있는 값들을 다른 변수의 "특정 메모리값"으로 복사할 때 사용함
// 주로 배열을 깊은 복사할 때 사용함 
int a[5], temp[5];
int main(){
    for(int i = 0; i < 5; i++) a[i] = i;
    memcpy(temp, a, sizeof(a));  // temp라는 배열에 a를 담음 

    a[4] = 1000; // 원본 배열 a를 수정하고 뭐 하는 로직
    memcpy(a, temp, sizeof(temp)); // a에 temp를 담음으로써 원본 배열 a로 돌아옴
}

// sort(first, last, *커스텀비교함수): 배열 등 컨테이너들의 요소를 정렬하는 함수 (O(nlogn))
// 세번째 인자에 아무것도 넣지 않으면 기본적으로 오름차순이다
vector<int> a;
int b[5];
int main(){
    for(int i = 5; i >= 1; i--) b[i - 1] = i;
    for(int i = 5; i >= 1; i--) a.push_back(i);

    // 오름차순 (default)
    sort(b, b + 5);
    sort(a.begin(), a.end());
    sort(b, b + 5, less<int>());
    sort(a.begin(), a.end(), less<int>());

    // 내림차순
    sort(b, b + 5, greater<int>());
    sort(a.begin(), a.end(), greater<int>());
}
// pair를 기반으로 만들어진 vector의 경우 따로 설정하지 않으면 first > second > third순으로 차례차례 오름차순 정렬된다
// 내림차순 정렬을 하고 싶거나 first는 내림차순, second는 오름차순 정렬을 하고 싶으면 "커스텀 연산자"를 사용!
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first; // first는 내림차순 정렬
}
int main(){
    for(int i = 10; i >= 1; i--){
        v.push_back({i, 10 - i}); // {{10, 1}, {9, 2}, ... {1, 9}}
    }
    sort(v.begin(), v.end(), cmp);  
}

// unique(): 범위안에 있는 요소 중 중복되는 요소를 제거하고 중복되지 않은 요소들로 앞에서부터 정렬되어 채움
// 그리고 나서 나머지 요소들은 삭제하지 않고 그대로 둠 (O(n))
vector<int> v;
int main(){
    for(int i = 1; i <= 5; i++){
        v.push_back(i);
        v.push_back(i);
    }
    for(int i : v) cout << i << " "; // 1 1 2 2 3 3 4 4 5 5
    cout << "\n";

    // 원본 배열 자체를 수정함
    auto it = unique(v.begin(), v.end()); // 중복되지 않은 요소들로 앞에서부터 채운 후, 그 다음 이터레이터를 반환함
    cout << it - v.begin() << "\n"; // 5

    for(int i : v) cout << i << " "; // 1 2 3 4 5 1 2 3 4 5
    cout << "\n";
}

// unique함수를 통해 중복되지 않은 요소들의 집합을 만들 수 있음
// sort, unique, erase순서임 (sort를 하는 이유? 중복되는 원소들이 인접해있어야 중복되었다고 판단 가능)
vector<int> v;
int main(){
    for(int i = 1; i <= 5; i++){
        v.push_back(i);
    }
    for(int i = 5; i >= 1; i--){
        v.push_back(i);
    }
    // v = {1,2,3,4,5,5,4,3,2,1}
    sort(v.begin(), v.end()); // v = {1,1,2,2,3,3,4,4,5,5}
    v.erase(unique(v.begin(), v.end()), v.end()); // v = {1,2,3,4,5}
}

// lower_bound(): 어떠한 값의 이상이 되는 위치 (0번째부터 탐색)
// upper_bound(): 어떠한 값이 나오기 전의 위치 (뒤에서부터 탐색)
// 정렬된 배열에서 어떤 값이 나오는 지점이나 어떤 값이 나오기전의 위치를 반환할 때 사용
// 이분탐색을 쉽게 함수로 구현하기 위해 사용
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int a[5] = {1,2,2,2,3};
    for(int i = 0; i < 5; i++) v.push_back(a[i]); // v = {1,2,2,2,3}
    int x = 2;

    // 2가 나오기 전의 위치(4) - 2이상이 되는 위치(1) = 4-1 = 3
    // x의 개수를 이런 방식으로 셀 수 있다 (중요!!)
    int c = (int)(upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x)); 
    
    int f = (int)(lower_bound(v.begin(), v.end(), x) - v.begin()); // 2이상이 되는 위치의 인덱스
    int t = (int)(upper_bound(v.begin(), v.end(), x) - v.begin()); // 2가 나오기 전 위치의 인덱스

    int f2 = *lower_bound(v.begin(), v.end(), x); 
    int t2 = *upper_bound(v.begin(), v.end(), x);
    cout << x << "의 개수: " << c << ", 시작되는 위치: " << f << ", 끝나는 위치: " << t << "\n";
    cout << "lower bound가 시작되는 점의 값: " << f2 << ", upper bound가 시작되는 점의 값: " << t2 << "\n"; 
    
    // x가 나오기 전의 위치 - x의 이상이 되는 위치 = 4-1 = 3
    c = (int)(upper_bound(a, a + 5, x) - lower_bound(a, a + 5, x));
    f = (int)(lower_bound(a, a + 5, x) - a); // x값의 이상이 되는 위치
    t = (int)(upper_bound(a, a + 5, x) - a); // x가 나오기 전의 위치 

    f2 = *lower_bound(a, a + 5, x);
    t2 = *upper_bound(a, a + 5, x);
    cout << x <<"의 개수: " << c << ", 시작되는 위치: " << f << " 끝나는 위치: " << t << "\n";
    cout << "lower bound가 시작되는 위치의 값: " << f2 << ", upper bound가 시작되는 위치의 값: " << t2 << "\n";
}

// 만약 원소를 찾을 때 값이 없다면 그 근방 지점을 반환한다
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    for(int i = 2; i <= 5; i++) v.push_back(i);
    v.push_back(7);
    // v = {2,3,4,5,7}

    cout << upper_bound(v.begin(), v.end(), 6) - v.begin() << "\n"; // 6이 나오기 전의 위치 인덱스 = 4
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() << "\n"; // 6이상의 값의 위치 인덱스 = 4
    
    // 값이 없다면 그 근방지점을 반환하는 예제
    cout << upper_bound(v.begin(), v.end(), 9) - v.begin() << "\n"; // 9가 나오기 전의 위치 인덱스 = 5
    cout << lower_bound(v.begin(), v.end(), 9) - v.begin() << "\n"; // 9이상의 값의 위치 인덱스 = 5

    cout << upper_bound(v.begin(), v.end(), 0) - v.begin() << "\n"; // 0이 나오기 전의 위치 인덱스 = 0
    cout << lower_bound(v.begin(), v.end(), 0) - v.begin() << "\n"; // 0이상의 값의 위치 인덱스 = 0
}


// ---------------------------66~70p까지 건너뜀
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