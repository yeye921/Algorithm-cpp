// 시간 초과난 나의 풀이 > ios_base... 추가하니 통과됨!
// O(n^2) = 9천만까지 가능
// 벡터 내 원소 삭제하는 법: v.erase(remove(v.begin(), v.end(), 지우고 싶은 원소), v.end());
//                   : v.erase(v.begin() + i);

// erase와 remove에 대한 공부해서 정리해놓는거 필요함 !
// find의 반환 값이나 v.begin() 같은 컨테이너의 주소는 *&연산자를 통해 출력해야함!

// split 함수를 꼭 써야할까? > 아님! 공백으로 분리되어 들어오니까 그냥 cin으로 받으면 됨!
// 배열에 배열을 대입하는법 ? memcpy이용
// 배열 초기화하는 법: fill이나 memset이용
// 배열에 배열 직접 대입 못함 !! (ex. a[] = {1, 2}; b[] = {}; b=a;)
// find 함수를 이용해서 시간초과가 나는 것 같으니까 배열을 이용하기 ! (배열은 -1로 초기화하기!) > 이렇게 해도 시간초과남
#include <bits/stdc++.h>
using namespace std;
int m, x, flag; // x는 -1로 초기화함으로써 체크할 수 있도록 함(벡터로 할까?  배열로 힐까?)
int og[20], all[20], empty; //  og[20] = {-1, } 이렇게 초기화하면 안됨
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(og, og + 20, -1);
    for(int i = 1; i < 21; i++) all[i - 1] = i;    
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> s;
        
        if(s == "all") memcpy(og, all, sizeof(all));
        else if(s == "empty") memset(og, -1, sizeof(og));
        else {
            cin >> x;

            if(og[x - 1] != -1) flag = 1;
            else flag = 0;

            if(s == "add" && !flag) og[x - 1] = x;
            else if(s == "remove" && flag) og[x - 1] = -1;
            else if(s == "check"){
                if(flag) cout << 1 << "\n";
                else cout << 0 << "\n";
            }
            else if(s == "toggle"){
                if(flag) og[x - 1] = -1;
                else og[x - 1] = x;
            }
        }
    }
}