#include <bits/stdc++.h>
using namespace std;
int a, b, A, B, C, cnt[101], sum; // 시간으로 배열을 만듬
int main(){
    cin >> A >> B >> C;

    for(int i = 0; i < 3; i++){
        cin >> a >> b;
        for(int j = a; j < b; j++){
            cnt[j]++;
        }
    }

    for(int i = 0; i < 101; i++){
        if(cnt[i]){
            if(cnt[i] == 1) sum += A;
            else if(cnt[i] == 2) sum += B * 2;
            else if(cnt[i] == 3) sum += C * 3;
        }
    }
    cout << sum;

    return 0;
}