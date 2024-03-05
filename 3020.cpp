#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int stone[500010];
int jong[500010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n, h;
    cin >> n >> h;
    for (int i=0 ; i< n/2 ; i++){
        //suksoon
        int stone_height;
        cin >> stone_height;
        stone[stone_height]+=1;
        int jong_height;
        cin >> jong_height;
        jong[h-jong_height]+=1;
    }

    for (int i =h-1 ; i >0 ; i--){
        stone[i] += stone[ i+1];
        jong[i] += jong[i+1];
    }
    for (int i = 0 ; i<=h ; i++){
        jong[i] = n/2 - jong[i];
    }
    int min = n+1;
    
    for (int i=0; i<h ; i++){
        if (min > stone[i]+jong[i]){
            min = stone[i]+jong[i];
        }
    }
    int cnt=0;
    for (int i=0; i<h ; i++){
        if (min == stone[i]+jong[i]){
            cnt+=1;
        }
    }

    cout << min  << ' ' << cnt ;
    
    return 0;
}