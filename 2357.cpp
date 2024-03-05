#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int max_tree[4*100000];
int min_tree[4*100000];

void update(int node, int start, int end, int idx, int value){
    if (idx < start || end < idx){
        return;
    }
    if (start == end){
        max_tree[node] = value;
        min_tree[node] = value;
        return;
    }

    
    int mid = (start+end)/2;
    update(node*2, start, mid, idx, value);
    update(node*2+1, mid+1, end, idx, value);
    max_tree[node] = max(max_tree[node*2],max_tree[node*2+1]);
    min_tree[node] = min(min_tree[node*2],min_tree[node*2+1]);
}

int get_max(int node, int start, int end, int left_idx, int right_idx){
    if (right_idx < start || end < left_idx) return 1;
    if (left_idx <= start && end <= right_idx) return max_tree[node];
    int mid = (start+end)/2;
    int left_result = get_max(node*2,start,mid, left_idx, right_idx);
    int right_result = get_max(node*2+1,mid+1,end, left_idx, right_idx);

    return max(left_result,right_result);
}

int get_min(int node, int start, int end, int left_idx, int right_idx){
    if (right_idx < start || end < left_idx) return 1000000001;
    if (left_idx <= start && end <= right_idx) return min_tree[node];
    int mid = (start+end)/2;
    int left_result = get_min(node*2,start,mid, left_idx, right_idx);
    int right_result = get_min(node*2+1,mid+1,end, left_idx, right_idx);

    return min(left_result,right_result);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,m;

    cin >> n >> m;

    for (int i=0; i<n; i++){
        int num;
        cin >>num;
        update(1,0,n-1,i,num);
    }

    for ( int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        int min_num = get_min(1,0,n-1,a-1,b-1);
        int max_num = get_max(1,0,n-1,a-1,b-1);
        cout << min_num << ' '<< max_num << '\n';
    }
    return 0;
}