// 보스 문제: 인접리스트 활용해서 루트노드부터 탐색하는게 제일 나은 풀이 !!
// ex.[2, 2, -1, 1, 5, -1, 5] > [2, 5] > [4, 2]

// 문자열 find() (ex. s.find("abc"))
// 반환값: 찾는 문자의 첫번째 인덱스 값 또는 string::npos

// 벡터 find() (ex. find(v.begin(), v.end(), "ab"))
// 반환값: 찾은 원소의 iterator를 반환해 줌. v.begin()을 빼줌으로써 인덱스 반환
// *it하면 찾는 값이 나옴, &*it으로 주소에 접근 가능함 (이터레이터는 이렇게 접근해야함)
#include <bits/stdc++.h>
using namespace std;
int sum;
vector<int> arr = {2, 2, -1, 1, 5, -1, 5}, in = {2, 5};
vector<int> ret, boss, adj[100005], cnt[100004]; // cnt에 조직별 조직원 수 순서대로 들어감 (boss순서와 cnt순서 일치함)
int dfs(int node){
    int ret = 1;
    for(int next : adj[node]){
        ret += dfs(next); 
    }
    return ret;
}
int main(){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == -1) boss.push_back(i);
        else adj[arr[i]].push_back(i); // 인접리스트 활용
    }

    for(int n : boss){
        // boss = 즉, 루트노드부터 탐색 시작
        sum = dfs(n); // 보스 인원 추가
        cnt[n].push_back(sum);
    }
    // boss에 포함된다면 조직원 수, 포함되지 않는다면 0을 배열에 넣음
    for(int n : in){
        // 해당 조직원의 아이디 값이 -1이면 보스인 것을 활용 > 이게 이전 방식보다 시간복잡도가 O(1)로 훨씬 낮음 
        if(arr[n] == -1){
            // 보스의 아이디를 통해서 해당 조직의 조직원 수를 어떻게 구하지..? > cnt배열을 보스의 아이디를 통해 접근할 수 있게 수정해야함
            ret.push_back(cnt[n][0]);
        }
        else ret.push_back(0);

        // 이전 방식
        // auto it = find(boss.begin(), boss.end(), n); // 여기서 시간복잡도 초과 날수도 있을 것 같음 O(n^2)
        // if(it != boss.end()) ret.push_back(cnt[it - boss.begin()]);
        // else ret.push_back(0);
    }
    for(int n : ret) cout << n << " ";
    cout << "\n";
}