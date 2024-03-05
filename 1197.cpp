#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    vector<pair<int,int>> linked[10100]; // -cost, next_node 저장

    int visit[10100];

    int v,e;

    cin >> v >> e;

    int a,b,cost;
    for (int i=0;i<e ; i++){   
        cin >> a >> b >> cost;
        linked[a].push_back(make_pair(-cost,b));
        linked[b].push_back(make_pair(-cost,a));
    }

    priority_queue<pair<int,int>> pq;

    int cur_node =1;

    long long total_cost=0;
    for (int i=0; i<v-1 ; i++){
        int edge_size = linked[cur_node].size();
        for (int j=0 ; j<edge_size ; j++){
            pq.push(linked[cur_node][j]);
        }
        visit[cur_node]=1;
        int neg_cost, next_node;

        while (!pq.empty()){
            neg_cost = pq.top().first;
            next_node = pq.top().second;
            pq.pop();
            if (visit[next_node]==0){
                break;
            }
        }

        total_cost += (-neg_cost);
        cur_node = next_node;

    }

    cout << total_cost;
    return 0;
}