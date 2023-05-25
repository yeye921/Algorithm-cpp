#include <iostream>
using namespace std;
int T;
int n;
int list[1004];
int visited[1004];
int main(){
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int ans = 0;
        fill(list, list + 1004, 0);
        fill(visited, visited + 1004, 0);
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> list[i];
        }
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            int send = i + list[i]; // 현재 편지 보낼곳의 idx
            int receive = send + list[send]; // 현재 보낼곳에서 편지를 보내는 idx
            if(i == receive){
                visited[i] = visited[send] = 1; // 중복 방지 처리
                ans++;
            }
        }
        cout << "#" << tc << " " << ans << "\n";
    }
}