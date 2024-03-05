#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long tree[4*1000010];
long long nums[1000010];

long long make(int node, int start, int end){
    if (start==end){
        return tree[node] = nums[start];
    }

    int mid = (start+end)/2;
    long long result_l = make(node*2,start,mid);
    long long result_r = make(node*2+1,mid+1,end);

    return tree[node] = result_l+result_r;
}

void update(int node, int start, int end, int idx, long long diff){
    if (idx < start || end < idx) return;
    tree[node] += diff;
    if (start != end){
        int mid = (start + end)/2;
        update(node*2, start, mid, idx, diff);
        update(node*2+1, mid+1, end, idx, diff);
    }
    return;
}

long long get_sum(int node, int start, int end, int left_idx, int right_idx){
    if (right_idx < start || end < left_idx) return 0;

    if (left_idx <= start && end <= right_idx) return tree[node];
    
    int mid = (start + end )/2;
    long long result_left = get_sum(node*2, start, mid, left_idx, right_idx);
    long long result_right = get_sum(node*2+1, mid+1, end, left_idx, right_idx);

    return result_right+result_left;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,m,k;
    cin >> n >> m >>k;

    for (int i=0; i<n; i++){
        cin >> nums[i];
    }

    make(1,0,n-1);
    
    m+=k;
    while (m--){
        int a,b;
        long long c;
        cin >> a >> b >> c;
        if (a==1){
            long long diff = c-nums[b-1];
            update(1,0,n-1,b-1, diff);
            nums[b-1]= c;
        }
        else{
            cout << get_sum(1,0,n-1,b-1,c-1) << '\n';
        }
    }

    return 0;
}