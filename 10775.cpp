#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int parking[100001];
int find_root(int a){
    if (a==parking[a]) return a;
    else return parking[a]=find_root(parking[a]);
}

void punion(int a, int b){
    int ra = find_root(a);
    int rb = find_root(b);
    if (ra!=rb){
        parking[ra] = rb;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int g;
    int p;
    cin >> g;
    cin >> p;
    
    for (int i=1;i<=g;i++){
        parking[i]=i;
    }

    int cnt=0;
    for (int i=0;i<g;i++){
        int gi;
        cin >> gi;
        // cout << gi << "\n";
        int root_gi = find_root(gi);
        if (root_gi==0) {
            break;
        }
        else {
            punion(root_gi,root_gi-1);
            cnt++;
            continue;
        }

    }
    cout << cnt;
    return 0;
}