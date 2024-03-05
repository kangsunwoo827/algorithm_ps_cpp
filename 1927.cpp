#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int arr[1000000]={0,};
int root=0;
int arr_size=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int iter=0; iter<n;iter++){
        int arg;
        cin >> arg ;
        if (arg==0){
            if (arr_size==0){
                cout << 0 << "\n";
            }
            else{
                cout << arr[1]<<"\n";
                arr[1] = arr[arr_size];
                arr_size--;

                int idx = 1 ;
                while (1){
                    if (idx*2 > arr_size){
                        break;
                    }
                    else if (idx*2 == arr_size){
                        if (arr[idx] > arr[idx*2]){
                            swap(arr[idx],arr[idx*2]);
                            idx*=2;
                        }
                        else break;
                    }
                    else {
                        if (arr[idx] <= arr[idx*2] && arr[idx] <= arr[idx*2+1]){
                            break;
                        }
                        else{
                            if (arr[idx*2] <= arr[idx*2+1]){
                                swap(arr[idx],arr[idx*2]);
                                idx*=2;
                            }
                            else {
                                
                                swap(arr[idx],arr[idx*2+1]);
                                idx=idx*2+1;
                            }
                        }
                    }
                }
            }
                
                
                
        }

        else {
            arr_size ++;
            arr[arr_size] = arg;
            int i = arr_size; 
            while (i>1){
                if (arr[i/2] > arr[i]){
                    swap(arr[i/2],arr[i]);
                    i/=2;
                }
                else{
                    break;
                }
                
            }
        }

        }
 

    return 0;
}