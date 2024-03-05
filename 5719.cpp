#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<pair<int,int>> linked[501]; // next, cost
int dist[501]; // s에서 다른 노드를 가는 거리
vector<int> before[501]; 
const int MAXCOST=900000000;
int n,m,s,d;
    priority_queue<pair<int,int>> pq; // 다음 정점까지의 비용, 다음 정점 순으로 구성.

bool banned[510][510];

void delete_edge(int cur_node){
    for (int i=0; i< before[cur_node].size(); i++){
        if (banned[before[cur_node][i]][cur_node]) continue;
        banned[before[cur_node][i]][cur_node] =true;
        delete_edge(before[cur_node][i]);
    } 

}
// void print_func(int cur_node){
//     for (int i=0; i< before[cur_node].size(); i++){
//         cout << cur_node << " - " << before[cur_node][i] << endl;
//         print_func(before[cur_node][i]);
//     } 
// }


void dijkstra(){
    for (int i=0; i<=n; i++){
        dist[i]=MAXCOST;
    }
    pq.push(make_pair(0,s)); // s부터 시작
    dist[s]=0;

    while (!pq.empty()){
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // if (cur_node == d) break;
        if (cur_cost > dist[cur_node]) continue;


        for (int i=0; i< linked[cur_node].size() ; i++){
            int next_node = linked[cur_node][i].first;
            int cur_to_next_cost = linked[cur_node][i].second;

            if (banned[cur_node][next_node]) {
                continue;
            }
            if (dist[cur_node] + cur_to_next_cost < dist[next_node]){
                dist[next_node] = dist[cur_node] + cur_to_next_cost;
                before[next_node].clear();
                before[next_node].push_back(cur_node);
                pq.push(make_pair(-dist[next_node],next_node));
            }
            else if (dist[cur_node] + cur_to_next_cost == dist[next_node]) before[next_node].push_back(cur_node);
        }
    
    }
}
void init(){
    for (int i=0; i<=n; i++){
            linked[i].clear();
            before[i].clear();
        }

    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
            banned[i][j]=0;
        }
    }
    for (int i=0; i<=n; i++){
        dist[i]=MAXCOST;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    while (1){
        cin >> n >> m; // n 장소개수 // m도로개수
        if (n==0 && m==0) break;
        cin >> s >> d; // s 시작점 d 도착점
        // 초기화
        init();

        for (int i=0; i<m; i++){
            int u,v,p;
            cin >> u >> v >> p;
            linked[u].push_back(make_pair(v,p));
        }
       
        dijkstra();
        // if (dist[d]==MAXCOST) {
        //     cout << -1 << endl;
        //     return 0;
        // }
        delete_edge(d);
        // print_func(d);
        ///////////////////////
        ///////////////////////
        ///////////////////////
        ///////////////////////
        dijkstra();
        
        if (dist[d]==MAXCOST) cout << -1 << endl;
        else cout << dist[d] <<endl;

        
        // print_func(d);
    
    }
    return 0;
}