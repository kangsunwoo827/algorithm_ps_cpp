#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int depth[100001];
int parent[20][100001];
vector<int> connected[100001];
int n,m;

int sol(int u, int v){
    if (depth[u]>depth[v]) swap(u,v);

    for(int k=19;k>=0;k--){
        if (depth[parent[k][v]]>=depth[u]){
            v=parent[k][v];
        }
    }

    if (u==v) return u;

    for (int k=19;k>=0; k--){
        if (parent[k][u]!=parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }

    return parent[0][u];
    }



    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);


    int u,v,r;
    cin >> n;
    for (int i=1; i<=n-1;i++){
        cin >> u>> v;
        connected[u].push_back(v);
        connected[v].push_back(u);
    }
    

    // tree 순회
    queue<int> q;
    q.push(1);
    depth[1]=1; parent[0][1]=1;
    while (!q.empty()){
        int cur_node =q.front(); q.pop();
        
        for (int i=0; i<connected[cur_node].size();i++){
            int next_node = connected[cur_node][i];

            if (depth[next_node]!=0) continue;
            depth[next_node] = depth[cur_node]+1;
            parent[0][next_node] = cur_node;
            q.push(next_node);
        }
    }

    for (int i=1; i<20; i++){
        for (int node=1; node <=n; node++ ){
            parent[i][node] = parent[i-1][parent[i-1][node]];
        }
    }


    cin >> m;
    for (int i=1; i<=m;i++){
        cin >> r >> u >> v;
        int sol1=sol(r,u);
        int sol2=sol(r,v);
        int sol3=sol(u,v);
        int res=sol1;
        if (depth[sol2]>depth[res]) res=sol2;
        if (depth[sol3]>depth[res]) res=sol3;

        cout << res <<"\n";
    }

    return 0;
}