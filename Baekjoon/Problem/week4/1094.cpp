// Q. 벡터에 인덱스를 지정해서 원소를 삽입할 수 있나? > 있음
// v.insert(v.begin() + 2, 3); // 2번째 위치에 3을 삽입함

// 벡터의 맨 마지막 원소 삭제하는 법: v.erase(v.end() - 1) (-1 해주는거 중요함!)
// 주의) 벡터의 맨 마지막 끝에 삽입할 때는 v.end()이다 !
#include <bits/stdc++.h>
using namespace std;
int x, og = 64, total_sum, _min;
vector<int> v; // Q. 스택으로 하는게 더 낫지 않을까? ... 고민 필요함
int main(){
    cin >> x; // x는 64일 수 있음

    v.push_back(og);
    while(1){ // 막대의 총 합이 x보다 크면 반복함
        total_sum = 0; // 각 경우마다 초기화 중요함
        for(int n : v) total_sum += n; // => 여기서 시간복잡도 n
        if(total_sum <= x) break;
        
        // 정렬을 쓰는게 맞을까??? > 맞음 > 정렬을 쓰므로써 1,2 둘다 해결가능함 
        sort(v.begin(), v.end());

        // 1) 가지고 있는 막대 중 길이가 가장 짧은 것 절반으로 자름 (반으로 잘라서 v에 넣는다는 의미)
        _min = v[0] / 2;
        v.erase(v.begin()); // 가장 짧은 막대를 지움
        v.push_back(_min); // 그것을 반으로 자른 것 2개 삽입
        v.push_back(_min);

        // 2) "위에서 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 길이의 합"이 x보다 크거나 같다면, 자른 막대의 절반 중 하나 버림 
        if((total_sum - _min) >= x){
            // 맨 뒤에 삽입되었을 거니까 pop_back() 이용
            v.pop_back();
        }
    }
    cout << v.size() << "\n";
    return 0;
}