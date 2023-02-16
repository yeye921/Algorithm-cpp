// 해당 비트가 켜져있음을 나타내는 코드
go(0, 0, 1 << (int)(a[0][0] - 'A'), 1);

// 비트마스킹을 이용한 완전탐색 코드
void go(int y, int x, int alpha, int cnt){
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nc >= c) continue;
        int next = 1 << (a[ny][nx] - 'A');
        if((alpha & next) == 0) go(ny, nx, alpha | next, cnt + 1);
    }
}
// 비트마스킹을 이용해서 HTT=6으로 나타내는 법
for(int i = 0; i < n; i++){
    cin >> s; int val = 1;
    for(int j = 0; j < n; j++){
        if(s[j] == 'T') a[i] |= val;
        val *= 2;
    }
}

// 비트마스킹을 이용해서 완탐 진행
void go(int row){
    if(row == n){
        int sum = 0;
        for(int i = 1; i <= (1 << (n-1)); i*=2){
            int sum = 0;
            for(int j = 0; j < n; j++) if(a[j] & i) cnt++;
            sum += min(cnt, n-cnt);
        }
        ret = min(ret, sum);
        return;
    }
    go(row + 1);
    a[row] = ~a[row];
    go(row + 1);             
}