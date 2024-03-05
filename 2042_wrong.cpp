#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[1000001];

long long n,m,k,temp, a,b,c,sum;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;

    for (int i=0; i<n ; i++){
        cin >> temp;
        arr[i]= temp;
    }
    
    for (int i=0; i<(m+k); i++){
        cin >> a >> b >> c;

        if (a==1){
            arr[b-1] = c;
        }   
        else{
            sum=0;
            for (int idx=b-1; idx <c ; idx++){
                sum+=arr[idx];
            }
            cout << sum <<endl;
        }
    }
    return 0;
}