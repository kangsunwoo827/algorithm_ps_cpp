#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<pair<int,int>> linked[1001];
priority_queue<pair<int,int>> pq;
bool mst[1010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,m;
    cin >> n;
    cin >> m;

    int a,b,c;
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        // if (a==b)continue;
        linked[a].push_back(make_pair(b,c));
        linked[b].push_back(make_pair(a,c));
        if (i==0){
            pq.push(make_pair(0,a));
        }
    }

    int cnt=0;
    int cost=0;
    while(!pq.empty()){
        int cur_cost = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if (mst[cur_node]) continue;
        cnt++;
        mst[cur_node]=true;
        cost += cur_cost;

        for (int i=0; i<linked[cur_node].size();i++){
            int next_node = linked[cur_node][i].first;
            int next_cost =linked[cur_node][i].second;

            if (mst[next_node]) continue;
            pq.push(make_pair(-next_cost,next_node));
        }

        if (cnt==n) break;

    }

    cout << cost;
    return 0;
}