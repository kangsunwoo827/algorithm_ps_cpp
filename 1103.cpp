#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int board[51][51];
bool visited[51][51];
int dp[51][51];
int n,m;
bool flag=false;

int dfs(int x, int y){
    if (flag) return 0;
    if (x<0 || y<0 || x>=n || y>=m) return 0;
    if (board[x][y]==-1) return 0;
    if (visited[x][y]) {
        cout << -1;
        exit(0);
    }

    if (dp[x][y]!=0){return dp[x][y];
    }
    visited[x][y]=true;
    dp[x][y] = 0;
    dp[x][y]=max(dp[x][y],dfs(x+board[x][y],y)+1);
    dp[x][y]=max(dp[x][y],dfs(x-board[x][y],y)+1);
    dp[x][y]=max(dp[x][y],dfs(x,y+board[x][y])+1);
    dp[x][y]=max(dp[x][y],dfs(x,y-board[x][y])+1);
    visited[x][y]=false;
    return dp[x][y];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);


    cin >> n >> m;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            char c;
            cin >> c;
            if (c=='H') board[i][j]=-1;
            else board[i][j] =  int(c)-int('0');
        }
    }

    flag=false;
    int res=dfs(0,0);
    
    if (!flag) cout << res;
    else cout << -1;
    return 0;
}