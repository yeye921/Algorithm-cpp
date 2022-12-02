// 그래프 탐색 알고리즘: DFS, BFS, ... 등등
// 그래프를 탐색만 하면 => DFS 사용 (코드 더 짧음)
// 같은 가중치를 가진 그래프에서 최단 거리를 구하는 문제는 => BFS 사용 (레벨별 탐색 => queue 이용!)

// DFS: 어떤 노드부터 시작해 "인접한 노드들을 재귀적으로 방문하며" 방문한 정점은 다시 방문하지 않으며, 각 분기마다 가능한 가장 멀리 있는 노드까지 탐색하는 알고리즘
// BFS: 어떤 정점에서 시작해 다음 깊이의 정점으로 이동하기전 "현재 깊이의 모든 정점을 탐색하며" 방문한 정점은 다시 방문하지 않는 알고리즘입니다. 같은 가중치를 가진 그래프에서 최단거리알고리즘으로 쓰임

// 가로길이(열) = m, 세로길이(행) = n이라고 가정
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
bool a[51][51], visited[51];

void dfs(int y, int x){ // 재귀적
    visited[y][x] = 1;
    cout << y << " " << x << "\n"
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx] || a[ny][nx] == 0) continue; // 이미 방문했거나 이동할 수 없는 지역일 경우
        dfs(ny, nx);
    }
    return;
}

void bfs(int sy, int sx){ // 한번만 호출됨, level별 탐색 => 큐 이용!, visited로 최단거리 배열 만들기(중요!)
    visited[sy][sx] = 1; // 중요 ! (시작 지점은 항상 1로)
    cout << sy << " " << sx << "\n";
    queue<pair<int, int>> q;
    q.push({sy, sx});

    while(q.size()){ // 큐가 빌 때까지 반복
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){ // 4방향 탐색
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] || a[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;  // 최단 거리 배열 처리 !!
            q.push({ny, nx});
        }
    }
}