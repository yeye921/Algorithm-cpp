#include <iostream>
#include <vector>
using namespace std;
int n = 5, k = 3;
int a[5] = {1, 2, 3, 4, 5};
void print(vector<int> b){
    for(int i : b) cout << i << " ";
    cout << "\n";
}
void combi(int start, vector<int> b){
    if(b.size() == k){ // k개 뽑으면 종료
        print(b);
        return;
    }
    for(int i = start + 1; i < n; i++){
        b.push_back(i);
        combi(-1, b);
        b.pop_back();
    }
}
int main(){
    // 조합1) 재귀함수 이용
    vector<int> b;
    combi(-1, b);

    // 조합2) n중 for문 이용 (인덱스(i, j, k)를 바탕으로 뽑음)
    // for(int i = 0; i < 3; i++){ // 3개 중에 3개를 뽑는 경우의 수
    //     for(int j = i + 1; j < 3; j++){
    //         for(int k = j + 1; k < 3; k++){
    //             cout << i << " " << j << " " << k << "\n";
    //         }
    //     }
    // }
    // for(int i = 0; i < 5; i++){ // 5개 중에 3개를 뽑는 경우의 수
    //     for(int j = 0; j < i; j++){
    //         for(int k = 0; k < j; k++){
    //             cout << i << " " << j << " " << k << "\n";
    //         }
    //     }
    // }
}