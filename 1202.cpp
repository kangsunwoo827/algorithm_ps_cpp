#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

pair<int,int> jewerly_lst[300001]; // weight, value
int bag_lst[300001]; // capa
priority_queue<int> can_value;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    int n,k;
    cin >> n >>k;
    for (int i=0 ; i<n; i++){
        int weight, value;
        cin >> weight >> value;
        jewerly_lst[i].first=weight;
        jewerly_lst[i].second=value;
    }

    for (int i=0; i<k; i++){
        int capa;
        cin >> capa;
        bag_lst[i] = capa;
    }

    sort(jewerly_lst,jewerly_lst+n);
    sort(bag_lst,bag_lst+k);

    int jewerly_idx=0;
    long long result =0 ;
    for (int i=0; i<k; i++){
        while (bag_lst[i]>=jewerly_lst[jewerly_idx].first){
            can_value.push(jewerly_lst[jewerly_idx++].second);
        }
        
        if (!can_value.empty()){
            result +=  can_value.top();
            can_value.pop();
        }
    }

    cout << result;

    return 0;
}