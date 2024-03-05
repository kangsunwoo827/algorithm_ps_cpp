#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nums[1001];
int dp_arr[1001]; // n번째부터 봤을 대의 최대 증가 수열 길이
int before[1001];
int dp(int n) {
    if (dp_arr[n]!=0) return dp_arr[n];
    int max_len =0;
    int max_idx =0;
    for (int i=1; i<=n-1; i++){
        if (nums[i]<nums[n]){
            if (max_len < dp(i)){
                before[n] = i;
                max_len = dp(i);
            }
        }
    }

    return dp_arr[n] = max_len +1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;

    cin >> n;
    
    for (int i=1; i<=n ; i++){
        cin >> nums[i];
    }

    for (int i=1; i<=n ; i++){
        dp(i);
    }
    int max_idx = -1;
    int max_len = -1;
    for (int i=1; i<=n; i++){
        if (max_len < dp_arr[i]){
            max_len = dp_arr[i];
            max_idx = i;
        }
    }

    cout << max_len << "\n";

    int cur_idx = max_idx;
    vector<int> result;
    for (int i=1; i<=max_len; i++){
        result.push_back(nums[cur_idx]);
        cur_idx = before[cur_idx];
    }

    for (int i=max_len-1; i>=0; i--){
        cout << result[i] << " ";
    }



    // for (int i=1 ; i<=n ; i++){
    //     cout << dp(i) << endl;
    // }
    return 0;
}