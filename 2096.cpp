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

    int n;
    cin >> n;

    int max_arr[3] ={0,0,0};
    int min_arr[3] ={0,0,0};
    
    int new1,new2,new3,max1,max2,max3,min1,min2,min3;
    for (int i=0; i < n ; i++){
        cin >> new1 >> new2 >> new3;
        max1 = *max_element(max_arr,max_arr+2)+ new1;
        max2 = *max_element(max_arr,max_arr+3)+ new2;
        max3 = *max_element(max_arr+1,max_arr+3)+ new3;
        min1 = *min_element(min_arr,min_arr+2)+ new1;
        min2 = *min_element(min_arr,min_arr+3)+ new2;
        min3 = *min_element(min_arr+1,min_arr+3)+ new3;

        max_arr[0] = max1;
        max_arr[1] = max2;
        max_arr[2] = max3;
        
        min_arr[0] = min1;
        min_arr[1] = min2;
        min_arr[2] = min3;
    }

    cout << *max_element(max_arr,max_arr+3) <<' '<< *min_element(min_arr,min_arr+3);

    return 0;
}