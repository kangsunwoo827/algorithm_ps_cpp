#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,k;
    cin >> n >> k;

    for (int i=2; i<=n; i++){
        arr[i]=1;
    }

    int sosu;
    while (1){
        for (int i=2; i<=n; i++){
            if (arr[i]==1){
                sosu=i;
                break;
                }
            }
        int cur_num = sosu;
        while(cur_num <=n){
            if (arr[cur_num]==1){
                arr[cur_num]=0;
                if (k==1){
                    cout << cur_num;
                    return 0;
                }
                else{
                    k--;
                }}
            
            cur_num+=sosu;
        }
    }
    return 0;
}