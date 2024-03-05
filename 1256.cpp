#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;

long long comb_array[202][101];
long long comb(int a, int b){
    
    if (comb_array[a][b]!=0) return comb_array[a][b];

    if (a==b || b==0) {
        comb_array[a][b] =1;
        return 1;
        }
    else {
        long long result = comb(a-1,b-1) + comb(a-1,b);
        if( result > 1000000000) result = 1000000001;
        return comb_array[a][b]=result;
    }
}

void dp(int n, int m, long long k){
    if (m==0){
        for (int i=0; i<n ; i++){
            cout <<"a";
        }
        return;
    }
    else if (n==0){
        for (int i=0; i<m ; i++){
            cout <<"z";
        }
        return;
    }

    
    // else if (k==1){
    //     while(n--){
    //         result+="a";
    //     }
    //     while(m--){
    //         result+="z";
    //     }
    //     return result;
    // }

    // else if (k== comb(n+m,m)){
    //     while(m--){
    //         result+="z";
    //     }
    //     while(n--){
    //         result+="a";
    //     }
    //     return result;
    // }
    

    else if (k<=comb(n+m-1,m)){
        cout << "a";
        dp(n-1,m,k);
    }
    else{
        cout << "z";
        dp(n,m-1,k-comb(n+m-1,n-1));
    }
 
    // cout << "n" << n << "m" << m << "k" << k << "result" << result << endl;
    return ;

}

// aaz
// aza
// zaa


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n,m;
    long long k;

    cin >> n >> m >> k;
    if (comb(n+m,m) <k) {
        cout << -1;
    }
    else {
        dp(n,m,k);
        }
    

    return 0;
}