#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int,pair<int,int>>> edges;

int parent[1001];
int find_root(int node){
    if (node==parent[node]) return node;
    else return parent[node]=find_root(parent[node]);
}

void punion(int a, int b){
    int rootA = find_root(a);
    int rootB = find_root(b);
    parent[rootA]=rootB;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,m;

    cin >> n >> m;

    for (int i=0; i<m;i++){
        int a,b,c;
        cin >> a >>  b >> c;

        edges.push_back(make_pair(c,make_pair(a,b)));
      
    }

    sort(edges.begin(),edges.end());
    for (int i=0;i<n;i++){
        parent[i]=i;
    }

    int res = edges[0].first;
    int cnt=1;
    punion(edges[0].second.first,edges[0].second.second);
    for (int i=1; i<m; i++){
        int cur_cost = edges[i].first;
        int cur_a = edges[i].second.first;
        int cur_b = edges[i].second.second;

        if (find_root(cur_a)==find_root(cur_b)) continue;
        else{
            cnt++;
            punion(cur_a,cur_b);
            res+=cur_cost;
        }
        if (cnt == n-1) break;

    }

    cout << res;


    return 0;
}