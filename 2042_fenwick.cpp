#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,k;
long long tree[1000001] , nums[1000001];
void update(int idx, long long value){

    while (idx <=n){
        tree[idx] += value;
        idx += idx&-idx;

    }
}

long long get_sum(int idx){
    long long value = 0;

    while (idx > 0){
        value += tree[idx];
        idx -= idx&-idx;
    }
    return value;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;

    for (int i=1; i<=n ; i++){

        cin >> nums[i];
    }

    for (int i =1; i<=n ; i++){
        update(i, nums[i]);
    }
    m+=k;



    while (m--){
        int a,b;
        long long c;

        cin >> a >> b >> c;

        if (a==1){
            update(b,c-nums[b]);
            nums[b]=c;
        }

        else{
            if (!(b==1)){
                 cout << get_sum(c)-get_sum(b-1) << '\n';
            }
            else{
                cout << get_sum(c)<<'\n';
            }
        }

    }
    return 0;
}