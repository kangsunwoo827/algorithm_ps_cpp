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

int nums[1000010];
int ltor[1000010];
int rtol[1000010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i=0; i< n ; i++){
        cin >> nums[i];
    }

    int answer_idx = 0;

    ltor[0] = nums[0];
    ltor[1] = nums[0];
    rtol[n] = nums[n-1];
    rtol[n+1] = nums[n-1];

    for (int i=1; i<n; i++){
        ltor[i+1] = choidae(ltor[i+1],ltor[i]);
    }

    for (int i=n; i>0; i--){
        rtol[i-1] = choidae(rtol[i],rtol[i-1]);
    }

    for (int i=1;i<n;i++){
        cout << ltor[i];
    }

    int ans_choidae=0;
    int ans=-1;

    for (int i=0; i<n; i++){
        cout << "check" << nums[i] << ltor[i] <<  rtol[i+2]<<endl;
        int c_num = choidae(ltor[i],rtol[i+2]);

        if (c_num > ans_choidae && (nums[i]%c_num)!=0){
            ans = nums[i];
            ans_choidae = c_num;
        }
    }

    cout << ans_choidae << ' ' << ans;
    return 0;
}