#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int weight[17][17];



int count (int A){ //A집합속 1의 개수
    int cnt =0 ;
    for (;A!=0;A>>=1){
        if (A&1) cnt++;
    }
    return cnt;
}

bool isin(int A, int node){
    return ((A >> (node-2))&1)==1;
}
const int MAX_COST = 16*1000000;

int n;
int dp(int cur_node, int visited){
    int min_res= MAX_COST;
    for (int i=1;i<=n; i++){
        if (weight[cur_node][i]==0) continue;
        else if (isin(visited,i)) continue;
        visited|1<<(i)
        dp(int )
    }
    // not visited에 대해
    // return min ( dp(next_node, visited+cur_node) + cost)
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for ( int i=1; i<=n; i++){
        for (int j=1;j<=n;j++){
            cin >> weight[i][j];
        }
    }


    return 0;
}