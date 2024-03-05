#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dparr[101][101][2][2];

int dp(int x, int y, bool beforeRight, bool beforebeforeRight){
    int result=0;
    if (x<1 || y<1) return 0;
    if (x==1 && y!=1) return int((!beforeRight)&&(!beforebeforeRight));
    if (x!=1 && y==1) return int(beforeRight&&beforebeforeRight);
    if (x==1 && y==1 && beforebeforeRight==beforeRight) return 1;

    if (dparr[x][y][beforeRight][beforebeforeRight]!=0) return dparr[x][y][beforeRight][beforebeforeRight];
    if (beforeRight){
        if (beforebeforeRight){
            result += dp(x-2,y,true,true);
            result += dp(x-2,y,true,false);
            result += dp(x-2,y,false,false);
        } 
        else{
            result +=dp(x-1,y-1,false,true);
            result +=dp(x-1,y-1,false,false);
        }
    }

    else{
        if (beforebeforeRight){
            result +=dp(x-1,y-1,true,true);
            result +=dp(x-1,y-1,true,false);
        }
        else {
            result +=dp(x,y-2,true, true);
            result +=dp(x,y-2,false, true);
            result +=dp(x,y-2,false, false);
        }
    }
    // cout << x << " " << y << " " << beforeRight<<" " << beforebeforeRight <<" "<< result <<endl;
    return dparr[x][y][beforeRight][beforebeforeRight]= result%100000;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int w, h;
    cin >> w >> h;

    cout << (dp(w,h,true,false)+dp(w,h,false,true)+dp(w,h,true,true)+dp(w,h,false,false))%100000;

    return 0;
}