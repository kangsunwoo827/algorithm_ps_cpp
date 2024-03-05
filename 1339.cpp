#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int coef[27];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    string s;
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<s.length(); j++){
            int cur_num = int(s[j])-int('A');
            coef[cur_num]-=pow(10,s.length()-j-1);
        }
    }
    
    sort(coef,coef+26);
    for (int i=0; i<26;i++){
    }
    int res=0;
    for (int i=9; i>=1;i--){
        res-=(coef[9-i]*i);
    }

    cout << res;
    return 0;
}