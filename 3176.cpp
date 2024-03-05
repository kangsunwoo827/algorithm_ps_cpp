#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int depth[100100];
int parents[21][100100]; //k번째 부모 저장.
int min_cost_arr[21][100100]; // k번째 부모 사이의 최소 cost 저장.
int max_cost_arr[21][100100]; // k번째 부모 사이의 최대 cost 저장.

const int MAXCOST = 987654321;
vector<pair<int,int>> linked[100100];

pair<int,int> sol(int a, int b){
    if (depth[a] > depth[b]) swap(a,b); // 항상 b가 더 깊게

    int min_cost = MAXCOST;
    int max_cost = -MAXCOST;
    for (int i=20; i>=0 ; i--){
        if (depth[parents[i][b]] >= depth[a]) {
            min_cost = min(min_cost_arr[i][b],min_cost);
            max_cost = max(max_cost_arr[i][b],max_cost);
            b= parents[i][b];
        }
    } // 깊이 맞추기

    if (a==b) {return make_pair(min_cost,max_cost);} //둘이 같으면 공통조상임

    for (int i=20 ; i >=0 ; i--) {
        if (parents[i][a]!=parents[i][b]){
            min_cost = min(min_cost_arr[i][b],min_cost);
            max_cost = max(max_cost_arr[i][b],max_cost);
            min_cost = min(min_cost_arr[i][a],min_cost);
            max_cost = max(max_cost_arr[i][a],max_cost);
            a=parents[i][a];
            b=parents[i][b];

        }
    }
    min_cost = min(min_cost_arr[0][a],min_cost);
    max_cost = max(max_cost_arr[0][a],max_cost);
    min_cost = min(min_cost_arr[0][b],min_cost);
    max_cost = max(max_cost_arr[0][b],max_cost);
    return make_pair(min_cost,max_cost); // 하나만 올라가면 공통조상임
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    //linked 입력

    for (int i=1; i<=n-1; i++){
        int a,b,c;
        cin >> a >> b >> c;
        linked[a].push_back(make_pair(b,c));
        linked[b].push_back(make_pair(a,c));
    }

    // lca + index tree임.
    // 공통 조상을 구하고
    // index tree에 특정 노드의 자식들에 대한 간선의 최솟값과 최댓값을 저장하자.

    //parents와 depth 기록하기
    queue<int> q;
    q.push(1); parents[0][1]=0; depth[1]=1;
    while(!q.empty()){
        int cur_node = q.front(); q.pop();
        for (int i=0; i<linked[cur_node].size(); i++){
            int next_node = linked[cur_node][i].first;
            if (depth[next_node]!=0) continue;

            int cost = linked[cur_node][i].second;
            depth[next_node] = depth[cur_node]+1;
            parents[0][next_node] = cur_node;
            min_cost_arr[0][next_node] = cost;
            max_cost_arr[0][next_node] = cost;
            
            q.push(next_node);
        }
    }

    //parents들 추가적으로 더 기록
    for (int i=1; i<=20; i++){
        for (int node =1; node<=n; node++){
            parents[i][node] = parents[i-1][parents[i-1][node]];

            min_cost_arr[i][node] = min(min_cost_arr[i-1][node] , min_cost_arr[i-1][parents[i-1][node]]);
            max_cost_arr[i][node] = max(max_cost_arr[i-1][node] , max_cost_arr[i-1][parents[i-1][node]]);
        }
    }

    // depth가 0인 친구들부터 올라가며 

    int k;
    cin >> k;

    while (k--){
        int d,e;

        cin >> d >> e;
        pair<int,int> res = sol(d,e);
        cout << res.first << " " << res.second << "\n";
    }
    return 0;
}