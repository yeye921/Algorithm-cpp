// 두 수를 뒤집은 뒤에 그 중 더 큰 수를 찾는 문제

// 두 수를 뒤집는 방법: 1) string의 reverse()이용, 2) 같은 자릿수이기때문에 string으로 받아 각자리수 비교
#include <iostream>
#include <algorithm>
using namespace std;
string a, b;
int main(){
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int aa = stoi(a);
    int bb = stoi(b);
    int mx = max(aa, bb);
    cout << mx << "\n";
}

// m2) string으로 각자리수 비교 (둘다 3자리수이기 때문에 가능한 것)
#include <iostream>
#include <string>
using namespace std;
int main(){
    string a, b, ret;
    cin >> a >> b;
    
    // 뒤집는 행위를 뒤 자리수부터 비교하는 것으로 대신함 !! (포인트)
    for(int i = 2; i >= 0; i--){
        if(a[i] == b[i]) continue; // 각 자리수가 같으면 다음 자리수 비교
        if(a[i] > b[i]) ret = a;
        else ret = b;
        break;
    }
    // 수를 뒤집어서 출력해야 함으로
    cout << ret[2] << ret[1] << ret[0] << "\n";
}