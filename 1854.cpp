#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAXDIST = 987654321;
priority_queue<int> dist[1001]; // 젤 앞에 k안에 드는 경로 중 큰걸로 경로 (+로 거리 저장)
int update_cnt[1001]; // n번째 있는 친구를 몇번 개선했는지
vector<pair<int,int>> linked[1001] ;   // next, cost 저장

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i=1; i<=m ; i++){
        int a,b,c;
        cin >> a >> b >> c;
        linked[a].push_back(make_pair(b,c));
    }

    // for (int i=2; i<=n; i++){
    //     dist[i].push(MAXDIST);
    // }
    dist[1].push(0);

    priority_queue<pair<int,int>> pq; //-dist, nextnode

    pq.push(make_pair(0,1));

    while (!pq.empty()){
        int cur_cost = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dist[cur_node].top()<cur_cost) continue;

        for (int i=0; i<linked[cur_node].size(); i++){
            int next_node = linked[cur_node][i].first;
            int cur_to_next_cost = linked[cur_node][i].second;

            int another = cur_cost+ cur_to_next_cost;
            
            if (dist[next_node].size() < k) {
                dist[next_node].push(another);
                pq.push(make_pair(-another,next_node));
            }
            else if  (another< dist[next_node].top()){
                dist[next_node].pop();
                dist[next_node].push(another);

                pq.push(make_pair(-another,next_node));
            }
        }

    }

    // for (int i=1; i<=n; i++){
    //     cout << "checking " << i;
    //     for (int j=0; j<= update_cnt[i]; j++){
    //         cout << " " << dist[i][j];
    //     }
    //     cout <<endl;
    // }

    for (int i=1; i<=n; i++){
        if (dist[i].size() <k) cout << -1 << "\n";
        else cout << dist[i].top() << "\n";
    }



    return 0;
}