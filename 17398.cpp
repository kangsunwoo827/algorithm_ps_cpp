#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

pair<int,int> edge[100010];
int size_lst[100010];
int parent[100010];
int find(int a){
    if (a==parent[a]) return a;
    return parent[a] = find(parent[a]);
}
void union_func(int a, int b){
    int root_a = find(a);
    int root_b = find(b);

    if (root_a!=root_b){
        parent[root_a] = root_b;
        size_lst[root_b] += size_lst[root_a];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n, m, q;

    cin >> n >> m >> q;

    int x,y;
    for (int i=1;i<=m;i++){
        cin >> x >> y;
        edge[i] = make_pair(x,y);
    }

    for (int i=1; i<=n; i++){
        parent[i]=i;
    }

    vector<int> destroy_order;
    int will_destroy[100100];

    for (int i=1; i<=q; i++){
        int idx;
        cin >> idx;
        will_destroy[idx]=1;
        destroy_order.push_back(idx);
    }

    int a,b;
    for (int i=1; i<=n; i++){
        size_lst[i] = 1;
    }
    for (int i=1;i<=m; i++){
        if (will_destroy[i]==1) continue;
        a=edge[i].first;
        b=edge[i].second;
        union_func(a,b);

    }

    long long cost = 0;
    for (int i=q-1; i>=0; i--){
        



        int idx = destroy_order[i];
        a=edge[idx].first;
        b=edge[idx].second;
        int root_a = find(a);
        int root_b = find(b);

        // root가 같음 -> 비용이 0임
        if (root_a!=root_b){   
            cost += (size_lst[root_a] *size_lst[root_b]);
        }

        union_func(a,b);
    }

    cout << cost ;
    

    return 0;
}