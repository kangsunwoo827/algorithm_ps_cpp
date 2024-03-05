#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long tree[4*1000000];

long long  get_candy(int node, int start, int end, int rank){
    if (start==end){
        return end;
    }
    int mid = (start+end)/2;

    // 좌측으로 가는 경우
    if (tree[node*2] >= rank){
        return get_candy(node*2, start, mid, rank);
    }
    // 우측으로 가는 경우
    else{
        return get_candy(node*2+1, mid+1, end, rank-tree[node*2]);
    }

}

void add(int node, int start, int end, int taste, long long diff){
    if (taste < start || end < taste) return;
    if (start==end){
        tree[node] += diff;
        return;
    }

    int mid = (start+end)/2;
    add(node*2, start, mid, taste, diff);
    add(node*2+1, mid+1, end, taste, diff);

    tree[node] = tree[node*2]+tree[node*2+1];

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;

    cin >> n;
    
    int tree_size =1;
    while (tree_size<1000000){
        tree_size*=2;
    }

    while (n--){
        long long a;
        cin >> a;
        long long b,c;

        if (a==1){
            cin >> b;
            int taste =  get_candy(1,1,1000000,b);
            cout << taste << '\n';
            add(1,1,1000000,taste,-1);
        }
        else {
            cin >> b>> c;
            add(1,1,1000000,b,c);

        }
    }
    return 0;
}