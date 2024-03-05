#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long tree[3000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    int n,m,k;

    cin >> n >> m >> k;

    int tree_size = 1; // tree의 맨 밑 줄 개수

    while (tree_size < n){
        tree_size*=2;
    }

    for (int i =0 ; i < n ; i++){
        cin >> tree[tree_size+i];
    }

    for (int i= tree_size-1; i>0; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }

    int a;
    long long b,c;
    for (int i =0 ; i< (m+k); i++){
        cin >> a >> b >> c;
        // update
        if (a==1){
            int cur_idx = tree_size+b-1; 
            tree[cur_idx] = c;
            cur_idx/=2;
            while (cur_idx>=1){
                tree[cur_idx] = tree[cur_idx*2]+tree[cur_idx*2+1];
                
                cur_idx/=2;
            }
        }
        // get sum
        else {
            long long sum = 0;
            int left = tree_size + b-1;
            int right = tree_size + c-1;
            
            while (left<=right){
                if (left%2==1){
                    sum+=tree[left++];
                }

                if (right%2==0){
                    sum+=tree[right--];
                }

                left/=2;
                right/=2;
            }
            cout << sum << '\n';
            }
        }
    
    return 0;
}