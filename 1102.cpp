#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int cost[17][17];
const int MAXCOST = 987654321;
bool isin(int i, int mask){
    return mask&(1<<i);
}
int memo[1<<16];
int n;
priority_queue<pair<int,int>> pq; // -cost, next_node

int p;

int dfs(int cur_mask, int cnt){
    if (cnt>=p){
        return  0;
    }
    if (memo[cur_mask]!=-1) return memo[cur_mask];
    

    int res=MAXCOST;

    for (int i=0; i<n; i++){
        if (!isin(i,cur_mask)) continue; // 안켜져있는 애로는 못킴
        for (int j=0;j<n;j++){ // j를 킬거임
            if (isin(j,cur_mask)) continue;
            res= min(res, dfs((cur_mask|(1<<j)), cnt+1)+cost[i][j]);
        }
    }
    return memo[cur_mask]= res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);


    cin >> n;
    for (int i=0 ; i<n; i++){
        for (int j=0; j<n;j++){
            cin >>cost[i][j];
        }
    }

    for (int i=0; i<(1<<16); i++){
        memo[i]=-1;
    }

    string s;
    cin >> s;
    int bit_mask = 0;
    cin >>p;

    int count =0;
    for (int i=0;i<n;i++){
        if (s[i]=='Y'){
            bit_mask|=(1<<i);
            count ++;
        }
    }

    int answer = dfs(bit_mask,count);
    if (answer==MAXCOST) cout << -1;
    else cout << answer;
    return 0;
}