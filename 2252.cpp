#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> fromto[32000];
int degree[32000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,m;
    cin >> n >> m;

    for (int i=0; i<m ; i++){
        int a,b;
        cin >> a >> b;
        fromto[a].push_back(b);
        degree[b]++;
    }

    queue<int> q;

    for (int i=1; i<=n; i++){
        if (degree[i]==0){
            q.push(i);

        }
    }

    while (!q.empty()){
        int cur_node = q.front(); q.pop();
        cout << cur_node <<" ";
        
        for (int i =0; i<fromto[cur_node].size() ; i++){
            if (--degree[fromto[cur_node][i]]==0) {
                q.push(fromto[cur_node][i]);

            }
        }
    }

    return 0;
}