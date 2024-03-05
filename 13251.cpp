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

    int m;
    cin >> m;
    int color[51];
    int n=0;

    for (int i=0; i<m; i++){
        cin >> color[i];
        n += color[i];
    }
    int k;
    cin >> k;


    double result=0.0;
    for (int i=0; i<m; i++){
        if (k<=color[i]){
            double tmp =1;
            for (int j=0; j<k ; j++){
                tmp *= double(color[i]-j) / (n-j);

            }
            result +=tmp;
        }
    }
    cout << fixed;
    cout.precision(12);
    cout << result;

    return 0;
}