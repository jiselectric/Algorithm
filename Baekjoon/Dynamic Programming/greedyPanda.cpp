#include <iostream>

using namespace std;

int n;
unsigned int map[501][501], ans[501][501];

unsigned int dfs (int x, int y)
{
    if (ans[x][y])
        return ans[x][y];

    if (x > 1 && map[x][y] < map[x-1][y])
        ans[x][y] = max(ans[x][y], dfs(x-1, y));
    if (x < n && map[x][y] < map[x+1][y])
        ans[x][y] = max(ans[x][y], dfs(x+1, y));
    if (y > 1 && map[x][y] < map[x][y-1])
        ans[x][y] = max(ans[x][y], dfs(x, y-1));
    if (y < n && map[x][y] < map[x][y+1])
        ans[x][y] = max(ans[x][y], dfs(x, y+1));
    
    ans[x][y]++;
    return ans[x][y];
}

int main()
{
    unsigned int answer = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!ans[i][j])
                ans[i][j] = dfs(i, j);
            answer = max(ans[i][j], answer);
        }
    }
    
    cout << answer;
    return 0;
}