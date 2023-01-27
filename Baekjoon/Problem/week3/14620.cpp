// 조합(combination): n개중에 r개를 순서에 상관없이 중복없이 뽑는다 (ex. 0 1 2가 뽑히면 2 1 0이 뽑힐 수 없다) 

// 핵심 알고리즘
// 1. 100개 중에 3개 뽑음 > 조합 이용 (중첩 for문)
// 2. 꽃잎자리 안겹치는지 범위를 넘는지 확인
// 3. 최소 비용 갱신
#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int _min = 20000; // 최소값은 항상 최대값부터 갱신
int n, sum, a[13][13];
bool visited[13][13];
bool check(int num){
    int y = num / 10;
    int x = num % 10;
    if(visited[y][x]) return false;
    visited[y][x] = 1;
    sum += a[y][x];
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) return false; // 범위를 넘어가거나 다른 꽃잎과 겹치면 false
        visited[ny][nx] = 1;
        sum += a[ny][nx];
    }
    return true;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                // 각 씨앗에 대해 진행 (셋다 true여야함)
                // i,j,k가 하나의 테스트 케이스 ! (초기화 중요!)
                memset(visited, 0, sizeof(visited));
                sum = 0;
                if(check(i) && check(j) && check(k)){
                    // 최소값 갱신
                    _min = min(_min, sum);
                    // cout << "셋 다 만족 " << i << " " << j << " " << k << "\n";
                    for(int y = 0; y < n; y++){
                        for(int x = 0; x < n; x++){
                            cout << visited[y][x] << " ";
                        }
                        cout << "\n";
                    }
                } 
            }
        }
    }
    cout << _min << "\n";
    return 0;
}