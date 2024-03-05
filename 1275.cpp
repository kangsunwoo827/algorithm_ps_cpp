#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long tree[300000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    
    int n, q ;

    cin >> n >> q;

    int tree_size = 1;
    while (tree_size<n){
        tree_size*=2;
    }

    for (int i=0; i<n ; i++){
        cin >> tree[tree_size+i];
    }

    for (int i=tree_size-1; i>0; i--){
        tree[i] = tree[i*2]+tree[i*2+1];
    }

    int x, y, a;
    long long b;

    for (int i=0; i<q ; i++){
        cin >> x >> y >> a >> b;


        // get sum
        if (x>y){
            swap(x,y);
        }
        int left_idx = x+tree_size-1;
        int right_idx = y+tree_size-1;
        long long sum=0;
        while (left_idx<=right_idx){
            if (left_idx%2==1){
                sum+=tree[left_idx++];
            }
            if (right_idx%2==0){
                sum+=tree[right_idx--];
            }
            left_idx/=2;
            right_idx/=2;
        }
        cout << sum << '\n';
        // update

        tree[tree_size+a-1]=b;
        int cur_idx = (tree_size+a-1)/2;
        while (cur_idx>=1){
            tree[cur_idx] = tree[cur_idx*2] + tree[cur_idx*2+1]; 
            cur_idx/=2;
        }

    }
    return 0;
}