#include <bits/stdc++.h>
using namespace std;
int a[10][10], n, m;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	    scanf("%1d", &a[i][j]);
	}
    }
    return 0;
}
