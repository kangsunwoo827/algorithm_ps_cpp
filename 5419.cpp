#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tree[80000*4];
void update(int node, int start, int end, int idx, int diff){
    if (idx<start || end < idx) return;
    tree[node] += diff; 
    if (start==end) return;
    int mid = (start+end)/2;

    update(node*2,start,mid,idx,diff);
    update(node*2+1,mid+1,end,idx,diff);
    return;

}

int query(int node, int start, int end, int q1, int q2){
    if (end<q1 || q2 < start) return 0;
    if (q1<=start && end <= q2) return tree[node];
    int mid = (start+end)/2;
    return query(node*2,start, mid, q1,q2) + query(node*2+1, mid+1, end, q1,q2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    // xi가 나보다 크고, yi가 나보다 작은 애들의 개수를 더하자.

    // yi 오름차순으로 넣으면서 query xi 이상인 애들의 개수를 찍으면 될듯?
    int t;
    cin >> t;

    pair<int,int> island[80000];
    vector<int> x_vec;
    for (int iter=1; iter<=t; iter++){
        int n;
        cin >> n;

        x_vec.clear();
        for (int i=1; i<=n; i++ ) island[i] = make_pair(0,0);

        for (int i=1 ;i <=n ; i++){
            int x,y;
            cin >> x >> y;
            island[i] = make_pair(y,-x);
            x_vec.push_back(x);
        }


        vector<int> comp(x_vec);
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(),comp.end()),comp.end());

        lower_bound(comp.begin(),comp.end(),3)-comp.begin();

        int tree_size =1;
        while (tree_size<comp.size()) tree_size*=2;

        for (int i=1; i<=tree_size*2; i++) tree[i]=0;


        sort(island+1,island+1+n);

        long long res= 0;
        for (int i=1; i<=n; i++){
            int y = island[i].first;
            int x = -island[i].second;
            int comp_x = lower_bound(comp.begin(),comp.end(),x)-comp.begin()+1;
            res+=query(1,1,comp.size(),comp_x,comp.size());
            update(1,1,comp.size(),comp_x,1);
            // cout << "tree" << "idx" << comp_x << "val" << query(1,1,n,comp_x,comp_x)<<"\n";
            // cout << query(1,1,n,1,comp_x);
        }

        cout << res << "\n";







    }
    return 0;
}