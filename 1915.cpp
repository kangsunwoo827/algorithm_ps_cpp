#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp_arr[1001][1001];
int arr[1001][1001];

int dp(int x, int y){ // x, y를 포함하는 정사각형의 한 변 길이
    if (dp_arr[x][y]!=0) return dp_arr[x][y];
    if (x<1 || y <1) dp_arr[x][y]=0;
    else if (x==1 && y==1) dp_arr[x][y]=arr[x][y];
    else if (arr[x][y] ==0) dp_arr[x][y]=0;
    else  dp_arr[x][y] = min(dp(x-1,y-1),min(dp(x-1,y),dp(x,y-1))) +1 ;
    // cout << x << y << dp_arr[x][y] <<endl;
    return dp_arr[x][y];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,m;
    cin >> n >>m;

    for (int i=1; i <=n; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=m ; j++){
            int num = int(s[j-1]-'0');
            arr[i][j]= num;
            // cout << i << j <<arr[i][j] << endl;
        }
    }

    int res = 0;
    for (int i=1; i <=n; i++) {
        for (int j=1; j<=m ; j++){
            res= max(res,dp(i,j));
        }
    }
    cout << res*res;

    return 0;
}