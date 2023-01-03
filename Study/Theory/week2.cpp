// 숫자 문자열을 숫자처럼 정렬하는 법 => 아스키코드 이용
bool cmp(string a, string b){
    if(a.size() == b.size()) return return a < b;
    return a.size() < b.size();
}

// 문자열에서 위치로 삭제
string ret;
if(ret.size() && ret.front() == '0') ret.erase(ret.begin());

// n!의 오른쪽 끝에 있는 0의 개수 구하는 문제
// 0은 10을 통해서 만들어짐 > 10은 2와 5를 통해서 만들어짐 

int i = 666;
for(;; i++){
    if(to_string(i).find("666") != string::npos) n--;
    if(n == 0) brek;
}

// 짝짓기 문제는 stack 이용 !
// 문자열의 문자 하나씩 탐색하면서 아래 알고리즘 적용
// 1. ( => 무조건 push
// 2. ) => (를 만나면 pop & 스택이 비어있으면 return false
string s;
stack<char> stk;
bool check(string s){
    stack<char> stk;
    for(char c : s){
        if(c == '(') stk.push(c);
        else {
            if(!stk.empty()) stk.pop();
            else return false;
        }
    }
    return stk.empty();
}
for(char c : s){
    if(c == '(') stk.push(c);
    if(c == '[') stk.push(c);
    if(c == ')'){
        if(stk.empty() || stk.top() == '['){
            check = false; break;
        } else stk.pop();
    }
    if(c == ']'){
        if(stk.empty() || stk.top() == '('){
            check = false; break;
        } else stk.pop();
    }
}
if(!stk.size() && check != false) return true;
else return false;

// 2차원 배열 복사하는 법
memcpy(a, temp, sizeof(a));

// 2차원 배열 초기화하는 법
fill(&a[0][0], &a[0][0] + n * m, 0);
memset(a, 0, sizeof(a));

// 벡터에 담긴 pair들 접근하는 방법
vector<pair<int, int>> v;
for(pair<int, int> pi : v){
    cout << pi.first << pi.second << "\n";
}

// 벡터 초기화하는 법
v.clear();

// main에서 dfs 호출은 한번만 하면 됨
// 노드 삭제를 구현하는 방법 => 방문처리하거나 방문하지않거나

// 벡터 특정 값 삭제하는 법
v.erase(v.begin() + i); // i번째 원소 삭제
v.erase(remove(v.begin(), v.end(), 지울 값), v.end()); // 특정 값 삭제

// dfs 두가지 유형
// 1. void형 dfs
// 2. int형 dfs
void dfs(int here){
    cnt++;
    visited[here] = 1;
    for(int there : v[here]){
        if(visited[there]) continue;
        dfs(there);
    }
    return;
}
int dfs(int here){
    int ret = 1;
    visited[here] = 1;
    for(int there : v[here]){
        if(visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}