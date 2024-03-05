#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int data_arr[1025][1025];
int dp_arr[1025][1025];

int dp(int x,int y){
    if (x<1 || y<1) return 0;

    if (dp_arr[x][y]!=0) return dp_arr[x][y];
    else return dp_arr[x][y] = data_arr[x][y]+dp(x-1,y) + dp(x,y-1) - dp(x-1,y-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,m;
    cin >> n >> m;

    for (int i=1; i<=n ;i++){
        for (int j=1; j<=n ;j++){
            cin >> data_arr[i][j];
        }
    }


    while(m--){
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp(x2,y2) -dp(x2,y1-1) - dp(x1-1,y2) + dp (x1-1,y1-1) << "\n";

    }

    return 0;
}