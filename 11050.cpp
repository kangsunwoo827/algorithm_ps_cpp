#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp(int n, int k){
    if (n==k||k==0){
        return 1;
    }
    else{
        return dp(n-1,k) + dp(n-1,k-1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n, k;

    cin >> n >> k;

    cout << dp(n,k);

    return 0;
}