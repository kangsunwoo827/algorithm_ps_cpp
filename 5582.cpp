#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[4001][4001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    string s1, s2;

    cin >> s1;
    cin >> s2;

    int res =0;
    for (int i=0; i<s1.length(); i++){
        for (int j=0; j<s2.length(); j++){ 
            if (s1[i]==s2[j]){
                if (i==0||j==0){
                    dp[i][j]=1;
                }
                else {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                res= max(dp[i][j],res);
            }
        }
    }

    cout << res;




    return 0;
}