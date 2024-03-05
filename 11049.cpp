#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
pair<int,int> matrix[501];
long long dp[501][501]; // i번째~j번째  곱의 최소 연산 횟수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin>> n;

    for (int i=1; i<=n;i++){
        int r,c;
        cin >> r >> c;

        matrix[i]=make_pair(r,c);
    }

    for (int diff=1; diff<=n-1; diff++){
        for (int i=1; i<=n-diff; i++){
            int j= i +diff;

            for (int k=i; k<j; k++){ // i~k + k+1~j 합산
                long long cost = dp[i][k] + matrix[i].first *matrix[k].second*matrix[j].second + dp[k+1][j];

                if (cost<dp[i][j] | dp[i][j]==0) dp[i][j]=cost;
            }

        }
    }

    cout << dp[1][n] << "\n";
    return 0;
}