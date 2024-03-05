#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dist[101][101];
const int MAXDIST = 100000*101*101;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,m;

    cin >> n ; 
    cin >> m;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i==j)continue;
            dist[i][j] =MAXDIST;
        }
    }

    for (int i=1; i<=m ; i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        if (dist[x][y]==0) dist[x][y]= cost;
        else dist[x][y]= min(dist[x][y],cost);
    }


    for (int cur_node=1; cur_node<=n; cur_node++){
        for (int i=1; i<=n; i++){
            // if (dist[i][cur_node]==0) continue;
            for (int j=1; j<=n; j++){
                // if (dist[cur_node][j]==0) continue;
                
                if (dist[i][j] > dist[i][cur_node] + dist[cur_node][j]){
                    dist[i][j] = dist[i][cur_node] + dist[cur_node][j];
                }
            }
        }

    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (dist[i][j]==MAXDIST) cout << 0 <<" ";
            else cout << dist[i][j] <<" ";
        }
        cout <<"\n";
    }


    return 0;
}
