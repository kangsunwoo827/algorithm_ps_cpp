#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int choidae(int a, int b){
    if (a<b){
        swap(a,b);
    }

    if (b==0){
        return a;
    }
    else{
        return choidae(b,a%b);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int a1,a2, b1, b2;

    cin >> a1 >> a2;
    cin >> b1 >> b2;

    int boonmo = a2*b2;
    int boonsoo = a2*b1 + a1*b2;

    int c_num = choidae(boonmo, boonsoo);
    boonsoo/=c_num;
    boonmo/=c_num;
    cout << boonsoo << ' ' << boonmo;
    return 0;
}