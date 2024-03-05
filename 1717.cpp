#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1000010];
int find(int a){
    if (parent[a]==a) return a;
    else return parent[a] = find(parent[a]);



}

void union_func(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    if (root_a!=root_b){
        parent[root_a] = root_b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,m;
    cin >> n >> m;

    for (int i=0; i<=n; i++){
        parent[i]=i;
    }

    while (m--){
        int q,a,b;
        cin >> q >>a >>b ;

        if (q==0){
            union_func(a,b);
        }

        else{
            if (a==b || find(a)==find(b)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }

    return 0;
}