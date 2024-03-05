#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp_arr[1001][1001]; // 공통 부분 수열
string s1,s2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> s1;
    cin >> s2;

    for (int i=1; i<=s1.length();i++){
        for (int j=1; j<=s2.length();j++){
            if (s1[i-1]==s2[j-1]){
                dp_arr[i][j]=dp_arr[i-1][j-1]+1;
            }
            else{
                if (dp_arr[i-1][j] > dp_arr[i][j-1]){
                    dp_arr[i][j]=dp_arr[i-1][j];
                }
                else dp_arr[i][j] = dp_arr[i][j-1];
            }

        }
    }

    cout << dp_arr[s1.length()][s2.length()] << "\n";
    string LCS = "";
    int f_idx = s2.length();
    for(int row = s1.size(); row >= 1; row--){
        for(int col = f_idx; col >= 1; col--){
            if(dp_arr[row][col] == dp_arr[row-1][col]){
                // 바로 위 dp_arr값이 같으면 현재 열 값을 유지한다
                f_idx = col;
                break;
            }
            else if(dp_arr[row][col] == dp_arr[row][col-1]) continue;
            else{
                LCS = s1[row-1] + LCS;
            }
        }
    }
    cout << LCS;
    
    // cout << dp_arr[s1.length()][s2.length()] << "\n";


    return 0;
}