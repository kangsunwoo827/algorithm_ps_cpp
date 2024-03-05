#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100100];
int dp[100100];
int cal_dp(int i){
    if (i==0) return 0;
    if (dp[i]!=0) return dp[i];
    if (i==1) return dp[1] = arr[1];
    return dp[i] = cal_dp(i-1) + arr[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,m;
    cin >> n >> m;

    for (int i=1 ; i <= n; i++){
        cin >> arr[i];
    }


    for (int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        cout << cal_dp(b) - cal_dp(a-1) << "\n";
    }

    return 0;
}