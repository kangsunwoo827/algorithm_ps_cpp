#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool isin(int bit_mask, int i){
    return (bit_mask & (1<<i));
}
string words[51];

int n,k;
int res=0;
void dfs(int mask, int left_k, int before_learn){
    int cnt =0;
    if (left_k==0){
        for (int i=0; i<n; i++){
            bool flag =true;
            
            for (int j=0;j<words[i].length()-8;j++){
                if (!isin(mask,int(words[i][j+4]) -int('a'))) {
                    flag = false;
                    break;
                }
            }

            if (flag) cnt++;
        }
    }
    
    res = max(res,cnt);

    for (int i=before_learn+1; i<26;i++){
            if (!isin(mask,i)) dfs(mask|(1<<i),left_k-1,i);
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
 
    cin >> n >>k;

    if (k<5) {
        cout << 0;
        return 0;
    }

    for (int i=0;i<n;i++){
       cin >> words[i];
    }

    queue<pair<int,int>> q; // 남은 단어 비트마스킹, 남은 k

    // a가 0번째 1을 정의함.
    int bit_mask = 0;
    bit_mask = bit_mask | (1<<(int('a')-int('a')));
    bit_mask = bit_mask | (1<<(int('n')-int('a')));
    bit_mask = bit_mask | (1<<(int('t')-int('a')));
    bit_mask = bit_mask | (1<<(int('i')-int('a')));
    bit_mask = bit_mask | (1<<(int('c')-int('a')));

    dfs(bit_mask,k-5,0);
    cout << res << "\n";
    return 0;
}