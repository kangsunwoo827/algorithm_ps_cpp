#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nums[101];
long long dp_arr[101][22];

long long dp(int cur_n, int cal_res){ // n까지의 계산값이 cal_res인 경우의 수

    if (cur_n==1){
        if (cal_res == nums[1]) return 1;
        else return 0;
    }

    if (cal_res < 0 || cal_res>20) return 0;

    if (dp_arr[cur_n][cal_res]!=0) return dp_arr[cur_n][cal_res];
    else{
        return dp_arr[cur_n][cal_res]= dp(cur_n-1,cal_res-nums[cur_n]) + dp(cur_n-1, cal_res+nums[cur_n]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);


    int n;
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> nums[i];
    }

    cout << dp(n-1,nums[n]);
    return 0;
}