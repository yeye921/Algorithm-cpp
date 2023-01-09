// #1
// 2가지 수로 만들 수 있는 모든 경우의 수 구하기 => 2 * 2 * 2 * 2
#include <bits/stdc++.h>
using namespace std;
int n, arr[2] = {1, 2};
// bool visited[4];
int result[4];
int combination_count = 0;
void recursive(int idx){
    if(idx >= 4){
        for(int i = 0; i < 4; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < 2; i++){
        result[idx] = arr[i];
        recursive(idx + 1);
    }
}
int main(){
    recursive(0);
    cout << combination_count << "\n";
    return 0;
}

// #2
// m가지의 수들로 n자리 수를 중복을 허락하여 만드는 경우
// m * m * m (.. n번)
// #include <bits/stdc++.h>
// using namespace std;
// int result[7];
// bool visited[7];
// int cnt = 0;
// void make_game(int idx){
//     if(idx > 6){
//         cnt++;
//         for(int i = 1; i <= 6; i++){
//             cout << result[i] << " ";
//         }
//         cout << "\n";
//         return;
//     }
//     for(int j = 1; j <= 3; j++){
//         if(!visited[idx]){
//             result[idx] = j;
//             visited[idx] = true;
//             make_game(idx + 1);
//             visited[idx] = false;
//         }
//     }
// }
// int main(){
//     make_game(1);
//     cout << cnt << "\n";
//     return 0;
// }