#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int heapq[100010];
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);


    int n;
    cin >> n;
    int size = 0;
    while (n--){
        int q; cin >>q;
        if (q==0){
            if (!(size==0)){
                cout << heapq[1] << '\n';
                heapq[1] = heapq[size];
                size--;

                int cur_idx = 1;
                while (cur_idx<=size){
                    if (size <cur_idx*2){
                        break;
                    }
                    if (heapq[cur_idx*2] >heapq[cur_idx*2+1] || size<=cur_idx*2){
                        if (heapq[cur_idx]<heapq[cur_idx*2]){
                            swap(heapq[cur_idx],heapq[cur_idx*2]);
                            cur_idx*=2;
                        }
                        else{
                            break;
                        }
                    } 

                    else{
                        if (heapq[cur_idx]<heapq[cur_idx*2+1]){
                            swap(heapq[cur_idx],heapq[cur_idx*2+1]);
                            cur_idx= cur_idx*2+1;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
            else{
                cout << 0 <<'\n';
            }
        }
        else{
            heapq[++size] = q;
            int cur_idx =size;
            
            while (cur_idx>1){
                if (heapq[cur_idx/2] < heapq[cur_idx]){
                    swap(heapq[cur_idx/2],heapq[cur_idx]);
                    cur_idx/=2;
                }
                else{
                    break;
                }
            }
        }
    }


    return 0;
}
