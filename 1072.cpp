#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    long long x,y;
    cin >> x >>y ;

    long long origin_z = y*100/x; 

    //  100*(y+t) / (x+t) = new_z + a/(x+t)
    // 100y / x = origin_z + b/x
    // origin_z < new_z
    // (100y-b)/x < (100y+100t-a) / (x+t)
    // 100xy+100ty-bx-bt < 100xy + 100tx -ax
    // 100ty-100tx < bx-ax+bt
    // t(100y-100x-b) < bx-ax
    // t < (bx-ax)/(100y-100x-b)


    if (origin_z>=99) cout << -1;
    else{
        if ((x*origin_z+x-100*y)%(99-origin_z)==0){
            cout << ((x*origin_z+x-100*y)/ (99-origin_z) );
        }
        else {
        cout << 1 + ((x*origin_z+x-100*y)/ (99-origin_z) );
        }
    }
    return 0;
}