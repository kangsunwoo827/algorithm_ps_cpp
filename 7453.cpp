#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nums1[4001];
int nums2[4001];
int nums3[4001];
int nums4[4001];
int sum_nums1[17000000];
int sum_nums2[17000000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;

    cin >> n;


    for (int j = 0 ; j< n; j++){
            cin >> nums1[j] >> nums2[j]>> nums3[j]>> nums4[j];
        }

    int idx=0;
    for (int i=0; i<n;i++){
        for (int j=0; j<n;j++){
            sum_nums1[idx] = nums1[i] + nums2[j];
            // cout << sum_nums1[idx] << endl;
            sum_nums2[idx] = nums3[i] + nums4[j];
            idx++;
        }
    }
    // cout << idx <<"idx" ;
    // for (int i=0; i<(n*n) ; i++){
    //     cout << i << " "  <<sum_nums1[i] <<endl;
    // }
    sort(sum_nums1,sum_nums1+(n*n));
    sort(sum_nums2,sum_nums2+(n*n));

    // for (int i=0; i<n*n ; i++)cout << sum_nums1[i] <<endl;
    long long cnt=0;

    for (int i=0; i<n*n; i++){
        int target1 = sum_nums1[i];
        cnt += (lower_bound(sum_nums2,sum_nums2+n*n, -target1+1)-lower_bound(sum_nums2,sum_nums2+n*n, -target1));
    }
    // while (1){
    //     int summation = sum_nums1[p1]+sum_nums2[p2];

    //     if (summation)

    // }
    //         if(summation==0) cnt++;
    //         else if (summation >0) break;
    //     }
    // }

    cout << cnt;


    return 0;
}