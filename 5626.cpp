#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[2][10001]; // i번째 열에 h만큼 쌓여있을 경우의수
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;

    cin >> n;

    dp[1][0]=1;
    
    int h;
    cin >> h;
    for (int i=2; i<=n; i++){
        cin >> h;
        // cout << "i" << i << "\n";
        // cout << "h" << h << "\n";
        if (h==-1){ // 모든 높이가 다 가능함.
            for (int can_height= 0; can_height<=min(i-1,n-i)+1 ; can_height++){
                if (can_height==0) dp[i%2][can_height] = dp[(i-1)%2][can_height]+dp[(i-1)%2][can_height+1];
                else dp[i%2][can_height] = dp[(i-1)%2][can_height-1]+dp[(i-1)%2][can_height]+dp[(i-1)%2][can_height+1];
                // if (dp[i][can_height]==0) break;
            // cout << dp[i][can_height] << "\n";
            }
        }
        else {
            if (h==0) dp[i%2][h] = dp[(i-1)%2][h]+dp[(i-1)%2][h+1];
            else dp[i%2][h] = dp[(i-1)%2][h-1]+dp[(i-1)%2][h]+dp[(i-1)%2][h+1];
            // cout << dp[i%2][h] << "\n";
        }

    }

    cout << dp[n%2][0];



    return 0;
}