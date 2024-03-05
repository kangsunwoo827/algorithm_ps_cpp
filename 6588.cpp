#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>

using namespace std;

int is_not_sosu[1000010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    for (int i=2; i<=1000000; i++){
        if (is_not_sosu[i]==0){
            int cur_idx = i*2;
            while (cur_idx <=1000000){
                is_not_sosu[cur_idx]=1;
                cur_idx += i;
            }
        }
    }
    int n;
    

    while (1){
        cin >> n;
        if (n==0){
            break;
        }
        int sosu =3;
        bool flag = false;
        for (int sosu = 3; sosu <1000000; sosu+=2){
            if (is_not_sosu[sosu]==0 && is_not_sosu[n-sosu]==0){
                cout << n<< " = " <<  sosu << " + "<< n-sosu << "\n";
                flag = true;
                break;
            }
        }
        
        if (!flag){
            cout << "Goldbach's conjecture is wrong.\n" ;
        }
    }
    return 0;
}