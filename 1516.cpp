#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int time_lst[501];
int degree[501];
vector<int> graph[501];
int result[501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;


    int query;
    for (int i=1; i<=n ; i++){
        cin >> time_lst[i];
        while (1){
            cin >> query;
            if (query==-1){
                break;
            }
            else{
                degree[i]++;
                graph[query].push_back(i);
            }
        }
    }

    queue<int> q;

    for (int i=1; i<=n; i++){
        if (degree[i]==0){
            q.push(i);
            result[i]=time_lst[i];
        }
    }

    while (!q.empty()){
        int cur_node = q.front(); q.pop();

        for (int idx=0; idx<graph[cur_node].size(); idx++){
            int next_node = graph[cur_node][idx];
            result[next_node] = max(result[next_node], time_lst[next_node]+result[cur_node]);
            if (--degree[next_node] ==0) q.push(next_node);
        }
    }

    for (int i=1; i<=n; i++){
       cout << result[i] <<'\n';
    }


    return 0;
}