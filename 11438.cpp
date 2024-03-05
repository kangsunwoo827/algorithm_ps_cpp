#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int parents[20][100100]; // k,i -> 2^k번째 부모를 저장
int depth[100100]; // i의 깊이 저장
int check[100100]; // 갔었나?
vector<int> connect[100100];

int n,m;
void make_tree(){
    // root부터 돌면서 parents와 . depth 기록
    queue<int> q;

    q.push(1);
    depth[1]=1; parents[0][1]=1; check[1]=1;
    depth[0]=0;
    while (!q.empty()){
        int cur_node = q.front();q.pop();
        for (int i=0; i<connect[cur_node].size(); i++){
            int next_node = connect[cur_node][i];
            
            if (check[next_node]==0){
                check[next_node]=1;
                depth[next_node] = depth[cur_node]+1;
                parents[0][next_node] = cur_node;
                q.push(next_node);
            }
        }
    }

    // parents들 기록
    for (int k=1; k <20 ;k++){
        for (int node=1; node<=n; node++){
            parents[k][node] = parents[k-1][parents[k-1][node]];
        }
    }
}

int find_lca(int a, int b){
    if (depth[a]!=depth[b]){
        if (depth[a] > depth[b]) swap(a,b); // 항상 b가 더 깊이 있음
        // depth 맞추기
        for (int k=19; k>=0; k--){
            if (depth[parents[k][b]] >= depth[a]) {
                b=parents[k][b];
            }
        }
    }


    if (a==b) return a;

    // a,b 둘다 올릴거임. 뛰어봤는데 다르면 올라감. 같으면 지나쳤을 가능성이 존재.
    for (int k=19; k>=0; k--){
        if (parents[k][a]!=parents[k][b]){
            a=parents[k][a];
            b=parents[k][b];
        }
    }

    return parents[0][b];

}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);


    cin >> n;

    for (int i=1; i<=n-1; i++){
        int a,b;
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    make_tree();

    cin >> m;

    for (int i=1; i<=m; i++){
        int a,b;
        cin >> a >> b;
        cout << find_lca(a,b) << "\n";

    }
    return 0;
}