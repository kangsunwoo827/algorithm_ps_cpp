#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp_arr[301];
int stair[301];

int dp(int n){ // n번째를 밟았을 때의 최대 가치 // jump는 전 번에 2칸을 갔는가 여부.
    int result;
    if (n<1) return 0;
    if (dp_arr[n]!=0) return dp_arr[n];
    dp_arr[n] = max(dp(n-2),dp(n-3)+stair[n-1]) + stair[n];


    // cout << n  << " " << result << endl;
    return dp_arr[n];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >>n;

    for (int i=1; i<=n; i++){
        cin >> stair[i];
    }

    cout << dp(n);

    return 0;
}