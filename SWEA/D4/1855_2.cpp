#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
 
int t, n, x, h;
int parent[100001];
vector<int> v[100001];
int depths[100001];
int d[100001][21];
queue<int> q2;
 
void calDepths() {
    queue<int> q;
    q2.push(1);
    q.push(1);
    depths[0] = -1;
    d[1][0] = 0;
    depths[1] = 0;
 
    while (!q.empty()) {
        int now = q.front();
        q.pop();
 
        for (int next : v[now]) {
            depths[next] = depths[now] + 1;
            d[next][0] = now;
            q.push(next);
            q2.push(next);
        }
    }
}
 
ll solve(int a, int b) {
    int cnt = 0;
 
    if (depths[a] != depths[b]) {
        if (depths[a] > depths[b]) swap(a, b);
        for (int i = h; i >= 0; i--)
            if (depths[a] <= depths[d[b][i]]) {
                b = d[b][i];
                cnt += i+1;
            }
    }
 
    int ans = a;
    if (a != b) {
        cnt += 2;
        for (int i = h; i >= 0; i--) {
            if (d[a][i] != d[b][i]) {
                a = d[a][i];
                b = d[b][i];
                cnt += (1<<(i+1));
            }
            ans = d[a][i];
        }
    }
 
    return cnt;
}
 
int main() {
    scanf("%d", &t);
 
    for (int tc = 1; tc <= t; tc++) {
        scanf("%d", &n);
 
        for (int i = 0; i <= n; i++)
            v[i].clear();
 
        h = log2(n) + 1;
        for (int i = 2; i <= n; i++) {
            scanf("%d", &x);
            parent[i] = x;
            v[x].push_back(i);
        }
 
        calDepths();
 
        for (int j = 1; j <= h; j++)
            for (int i = 1; i <= n; i++)
                d[i][j] = d[d[i][j - 1]][j - 1];
 
        ll ans = 0;
 
        int start = q2.front();
        q2.pop();
 
        while (!q2.empty()) {
            int next = q2.front();
            q2.pop();
            ans += solve(start, next);
 
            start = next;
        }
 
        printf("#%d %lld\n", tc, ans);
    }
}