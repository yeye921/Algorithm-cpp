#include<iostream>
#include<queue>
#include<set>
using namespace std;
 
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
 
int main(void)
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        char num_map[4][4];
 
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> num_map[i][j];
            }
        }
 
        set<string> num_set;
 
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                queue<pair<string, pair<int, int>>> q;
                string tok = "";
                tok += num_map[i][j];
                q.push({ tok, {i,j}});
 
                while (!q.empty())
                {
                    auto elem = q.front();
                    q.pop();
 
                    for (int d = 0; d < 4; d++)
                    {
                        int ny = elem.second.first + dy[d];
                        int nx = elem.second.second + dx[d];
 
                        if (0 <= ny && ny < 4 && 0 <= nx && nx < 4)
                            ;
                        else
                            continue;
 
                        string s = elem.first + num_map[ny][nx];
 
                        if (s.size() == 7) {
                            num_set.insert(s);
                        }
                        else {
                            q.push({ s, {ny,nx} });
                        }
                    }
                }
            }
 
        }
 
        cout << "#" << t << " " << num_set.size() << "\n";
 
    }   
 
}